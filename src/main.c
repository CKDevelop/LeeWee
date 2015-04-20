#define _GNU_SOURCE
#include <stdio.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>
#include <time.h>

#define LG_MAX 40960

static char *ENV[LG_MAX];

#include "regex.c"
#include "regex_const.c"
#include "str.c"
#include "console.c"
#include "variables.c"

#include "tokens.h"

void getVarsRequest(char* VARSQUERY) {
    int nameget=0;
    int i;
    if (VARSQUERY != NULL) {
        char *var_name=(char *)malloc (sizeof (char) * LG_MAX);
        char *var_value=(char *)malloc (sizeof (char) * LG_MAX);
        memset (var_name, 0, strlen (var_name));
        memset (var_value, 0, strlen (var_value));
        for(i=0;i<=strlen(VARSQUERY);i++) {
            if (VARSQUERY[i]!='\0') {
                if (VARSQUERY[i]=='=') {
                    nameget=1;
                } else if (VARSQUERY[i]=='&') {
                    nameget=0;
                    libererVariable(mes_variables, var_name);
                    mes_variables=ajouterVariable(mes_variables, var_name, var_value);
                    memset (var_name, 0, strlen (var_name));
                    memset (var_value, 0, strlen (var_value));
                } else {
                    if (nameget==0) {
                        strncat(var_name, &VARSQUERY[i], 1);
                    } else {
                        strncat(var_value, &VARSQUERY[i], 1);
                    }
                }
            } else {
                nameget=0;
                libererVariable(mes_variables, var_name);
                mes_variables=ajouterVariable(mes_variables, var_name, var_value);
                memset (var_name, 0, strlen (var_name));
                memset (var_value, 0, strlen (var_value));
            }
        }
    }
}
void dbg(char *msg) {
    printf("Content-type: text/plain;charset=utf-8\n\n");
    printf("%s", msg);
    exit(0);
}

void dbgint(int msg) {
    printf("Content-type: text/plain;charset=utf-8\n\n");
    printf("%d", msg);
    exit(0);
}

int uploadFile() {
    int content_length;
    char *ligne_courante_tmp = (char *)malloc (sizeof(char) * LG_MAX);
    char *var_name=(char *)malloc (sizeof (char) * LG_MAX);
    char *var_value=(char *)malloc (sizeof (char) * LG_MAX);
    char *uploadtmp=(char *)malloc (sizeof (char) * LG_MAX);
    char *tmp_tmp = (char *)malloc(sizeof(char) * LG_MAX);
    char *tmp_tmp_tmp = (char *)malloc(sizeof(char) * LG_MAX);
    content_length = atoi(getenv("CONTENT_LENGTH")); 
    if(content_length > 0) {
        FILE* fileupload = NULL;
            int ni; 
            int nc;
            time_t timestamp; 
            struct tm * t; 
            timestamp = time(NULL); 
            t = localtime(&timestamp); 
            sprintf(uploadtmp,".%04u%02u%02u%02u%02u%02u", 1900 + t->tm_year, t->tm_mon,t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

            //on compte le nombre de ligne
            FILE *ftmp = fopen(uploadtmp, "wb");
            for ( ni = 0; ni < content_length && (nc = getchar()) != EOF ; ni++ ) {
                fputc ( nc, ftmp );
            }
            fclose(ftmp);
            ftmp = fopen (uploadtmp, "rb");
            int skipline=0;
            int skipfile=0;
            while(fgets(ligne_courante_tmp, LG_MAX, ftmp) != NULL) {
                
                if (str_istr(ligne_courante_tmp,"WebKitFormBoundary")!= -1) continue;
                if (str_istr(ligne_courante_tmp,"Content-Disposition")!=-1) {
                    skipfile=0;
                    //on stock la variable pour le name_filename
                    tmp_tmp=regex_const(ligne_courante_tmp,TOKEN_VAR_NAME_FILEUPLOAD_1);
                    var_name=str_replace(tmp_tmp,0,8,"");
                    strcpy(tmp_tmp_tmp,var_name);
                    strcat(var_name, "_filename");
                    tmp_tmp=regex_const(ligne_courante_tmp,TOKEN_VAR_FILENAME_FILEUPLOAD_1);
                    var_value=str_replace(tmp_tmp,0,12,"");
                    var_value=str_replace(var_value,strlen(var_value)-1, 1,"");

                    if (strlen(var_value)<=0) {skipfile=1;continue;}
                    libererVariable(mes_variables, var_name);
                    mes_variables=ajouterVariable(mes_variables, var_name, var_value);
                    if (fileupload != NULL) {
                        //fputc ( '\0', fileupload );
                        fclose(fileupload);
                    }
                    fileupload = fopen(var_value, "w+b");
                    
                    continue;
                }
                if (str_istr(ligne_courante_tmp,"Content-Type")!=-1 && skipfile==0) {
                    //on stock la variable pour le name_type
                    strcpy(var_name,tmp_tmp_tmp);
                    strcat(var_name, "_type");
                    tmp_tmp=regex_const(ligne_courante_tmp,TOKEN_VAR_TYPE_FILEUPLOAD_1);
                    var_value=str_replace(tmp_tmp,0,14,"");
                    libererVariable(mes_variables, var_name);
                    mes_variables=ajouterVariable(mes_variables, var_name, var_value);
                    skipline=1;
                    memset (var_name, 0, strlen (var_name));
                    memset (var_value, 0, strlen (var_value));
                    continue;
                }
                if (skipline==0 && skipfile==0) {
                    for ( ni = 0; ni < content_length && (nc = ligne_courante_tmp[ni]) != '\n' ; ni++ ) {
                        fputc ( nc, fileupload );
                    }
                    fputc ( '\n', fileupload );
                } else skipline=0;
                
            }
            if (fileupload != NULL) fclose(fileupload);
            if (fileupload != NULL) fclose(ftmp);
            remove(uploadtmp);
            return 1;
        
    } else return 0;
}

int main(int argc, char *argv[], char *envp[]) {
    char c;
    int i;
    char *tmp = (char *)malloc(sizeof(char) * LG_MAX);

    char *ligne_courante = (char *)malloc (sizeof(char) * LG_MAX);
     
    int ctmp=0;
    int multiline=0;
    int pstr=-1;
    char *tmp_tmp = (char *)malloc(sizeof(char) * LG_MAX);
    char *tmp_tmp_tmp = (char *)malloc(sizeof(char) * LG_MAX);
    int display_var=0;
    char *var_name=(char *)malloc (sizeof (char) * LG_MAX);
    char *var_value=(char *)malloc (sizeof (char) * LG_MAX);
    
    int pos_html=0;
    int condition=0;
    int condition_count=-1;
    int condition_etat=0;
    char **tableau_value = NULL;
    int CONDITION[LG_MAX];

    char* GET;
    if((GET=getenv("QUERY_STRING"))) {
        urldecode(GET);
        getVarsRequest(GET);
    }
    char* REQUESTMETHOD;
    int fileup=0;
    REQUESTMETHOD=getenv("REQUEST_METHOD");
    if (str_istr(REQUESTMETHOD,"POST")> -1 ) {
        int content_length;
        char *POST ;
        if ( strcasecmp(getenv("CONTENT_TYPE"), "application/x-www-form-urlencoded")) {
            if( strcmp(getenv("CONTENT_TYPE"), "multipart/form-data")) {
                //Upload file
                fileup=uploadFile();
            } else dbg("LeeWee: Unsupported Content-Type.\n") ;
        }
        if (fileup==0) {
            if ( !(content_length = atoi(getenv("CONTENT_LENGTH"))))
                dbg("LeeWee: No Content-Length was sent with the POST request.\n") ;
            if ( !(POST= (char *) malloc(content_length+1)))
                dbg("LeeWee: Couldn't malloc for POST.\n");
            if (!fread(POST, content_length, 1, stdin))
                dbg("LeeWee: Couldn't read CGI input from STDIN.\n");
            urldecode(POST);
            getVarsRequest(POST);
        }
    }

    FILE *SCRIPT = fopen (argv[1], "r");
    if (SCRIPT) {
        while(fgets(ligne_courante, LG_MAX, SCRIPT) != NULL) {
            for(i=0;i<=strlen(ligne_courante);i++) {
                c= ligne_courante[i];
                switch(c) {
                    case '\n': 
                        if (display_var<2) display_var=0;
                        //si ça ne commence pas par # (commentaire) alors...
                        if ( ((tmp[0] != '#' && multiline==0) || (multiline==1)) && (tmp[0] != 0) ) {
                            /*si la ligne vaut $var=<? cmd ?>*/
                            if ((regex_match_const(tmp,TOKEN_VAR_1)==0 || regex_match_const(tmp,TOKEN_VAR_2)==0) && (multiline==0) && (condition_etat!=1)){
                                var_name=regex_const(regex_const(tmp,TOKEN_VAR_NAME_1),TOKEN_VAR_NAME_2);
                                tmp_tmp=regex(tmp,"(<\\?.*\\?>$)");
                                tmp_tmp=str_replace(tmp_tmp,0,2,"");
                                pstr=str_istr(tmp_tmp,"?>");
                                tmp_tmp=str_replace(tmp_tmp,pstr,2,"");
                                var_value=shell(tmp_tmp);
                                libererVariable(mes_variables, var_name);
                                mes_variables=ajouterVariable(mes_variables, var_name, var_value);

                            /*si la ligne vaut $var=<? cmd*/
                            } else if ((regex_match_const(tmp,TOKEN_VAR_START_1)==0 || regex_match_const(tmp,TOKEN_VAR_START_2)==0) && (multiline==0) && (condition_etat!=1)){
                                tmp_tmp=regex(tmp,"(<\\?.*$)");
                                tmp_tmp=str_replace(tmp_tmp,0,2,"");
                                //printf("%s\033[0m\n",tmp_tmp);
                                strncat(tmp, "\n", 1);
                                multiline=1;

                            /*si la ligne vaut cmd ?>*/
                            } else if (regex_match_const(tmp,TOKEN_VAR_END_1_2)==0 && (condition_etat!=1)){
                                if (regex_match(tmp,"^.*\\?>$")==0 ) {
                                    var_name=regex_const(regex_const(tmp,TOKEN_VAR_NAME_1),TOKEN_VAR_NAME_2);
                                    tmp_tmp=regex(tmp,"(.*\\?>$)");
                                    pstr=str_istr(tmp_tmp,"?>");
                                    tmp_tmp=str_replace(tmp_tmp,pstr,2,"");
                                    pstr=str_istr(tmp_tmp,"<?");
                                    tmp_tmp=str_replace(tmp_tmp,pstr,2,"");
                                    strcpy(tmp_tmp_tmp,tmp_tmp);
                                    tableau_value=str_split(tmp_tmp_tmp, "=");
                                    pstr=str_istr(tmp_tmp, tableau_value[0]);
                                    tmp_tmp=str_replace(tmp_tmp,pstr,strlen(tableau_value[0])+1,"");
                                    var_value=shell(tmp_tmp);
                                    libererVariable(mes_variables, var_name);
                                    mes_variables=ajouterVariable(mes_variables, var_name, var_value);
                                }
                                multiline=0;
                            } else if (multiline==1 && (condition_etat!=1)){
                                strncat(tmp, "\n", 1);

                            /*si la ligne vaut $var=str*/
                            } else if ((regex_match_const(tmp,TOKEN_VAR_3)==0) && (multiline==0) && (condition_etat!=1)){
                                var_name=regex_const(regex_const(tmp,TOKEN_VAR_NAME_1),TOKEN_VAR_NAME_2);
                                tmp_tmp=regex(tmp,"(=.*$)");
                                tmp_tmp=str_replace(tmp_tmp,0,1,"");
                                var_value=tmp_tmp;
                               //printf("##%s == %s\n",var_name,var_value);
                                libererVariable(mes_variables, var_name);
                                mes_variables=ajouterVariable(mes_variables, var_name, var_value);
                            /*si la ligne vaut if(.*){ */
                            //FIXME imbriquation condition !!
                            } else if (regex_match_const(tmp,TOKEN_IF_1)==0) {
                                //condition = 1 alors condition activé
                                // condition_etat= 1 alors condition vraie

                                condition=1;
                                condition_count++; 
                                if (CONDITION[condition_count-1]==0){
                                    condition_etat=0;
                                    CONDITION[condition_count]=0;
                                } else if (regex_match(tmp,"\\(.*!=.*\\)")==0){
                                    var_name=str_replace(str_replace(regex(tmp,"(\\(.*!=)"),strlen(regex(tmp,"(\\(.*!=)"))-2,2,""),0,1,"");
                                    var_value=str_replace(str_replace(regex(tmp,"(!=.*\\))"),strlen(regex(tmp,"(!=.*\\))"))-1,1,""),0,2,"");
                                    if (strcmp(var_name, var_value)==0) {
                                            condition_etat=0;
                                            CONDITION[condition_count]=0;
                                    } else {
                                            condition_etat=1;
                                            CONDITION[condition_count]=1;
                                    }
                                } else if (regex_match(tmp,"\\(.*==.*\\)")==0){
                                    var_name=str_replace(str_replace(regex(tmp,"(\\(.*==)"),strlen(regex(tmp,"(\\(.*==)"))-2,2,""),0,1,"");
                                    var_value=str_replace(str_replace(regex(tmp,"(==.*\\))"),strlen(regex(tmp,"(==.*\\))"))-1,1,""),0,2,"");
                                    if (strcmp(var_name, var_value)==0) {
                                            condition_etat=1;
                                            CONDITION[condition_count]=1;
                                    } else {
                                            condition_etat=0;
                                            CONDITION[condition_count]=0;
                                    }
                                }
                            } else if (regex_match_const(tmp,TOKEN_ELSE_1)==0 ){ 
                                condition=1;
                                    if (CONDITION[condition_count-1]==0){
                                        CONDITION[condition_count]=0;
                                        condition_etat=0;
                                    } else if (CONDITION[condition_count]==1 ) {
                                        CONDITION[condition_count]=0;
                                        condition_etat=0;
                                    } else if (CONDITION[condition_count]==0) {
                                        CONDITION[condition_count]=1;
                                        condition_etat=1;
                                    }
                            } else if (regex_match_const(tmp,TOKEN_IF_ELSE_END_1)==0){
                                    condition_count--;
                                    if (condition_count>=0 ) {
                                        if (CONDITION[condition_count]==1){
                                        condition_etat=1;
                                        }else {
                                        condition_etat=0;
                                        }
                                        condition=1;
                                    } else {
                                        condition=0;
                                        condition_etat=0;
                                    }
                            } else {
                                if (pos_html<=0) {
                                    printf("Content-type: text/html;charset=utf-8\n\n");
                                    pos_html=1;
                                }
                                if (condition==1 && condition_etat > 0) printf("%s\n",tmp);
                                else if (condition==0) printf("%s\n",tmp);
                            }
                        }
                        
                        if (multiline==0) bzero(tmp, LG_MAX);
                        break;
                    case '$':
                        display_var=1;
                        break;
                    case '[':
                        if (display_var==1) {
                            display_var=2;
                            if (strlen(tmp_tmp)>=0) strcpy(tmp_tmp,"");
                        } else {
                            strncat(tmp, &c, 1);
                        }
                        break;
                    case ']':
                        if (display_var==2) {
                            display_var=0;
                            strcat(tmp, afficherVariable(mes_variables, tmp_tmp));
                            //strcat(tmp, getVar(tmp_tmp,VARIABLES, ENV));
                        } else {
                            strncat(tmp, &c, 1);
                        }
                        break;
                    default:
                        if (display_var==1) {
                            display_var=0;
                            strncat(tmp, "$", 1);
                        }

                        if (display_var==2) {
                            strncat(tmp_tmp, &c, 1);
                            continue;
                        } else if (i==0) {
                            if (c==' ' && multiline==0) { ctmp=1; continue; }
                        } else {
                            if (c==' ' && ctmp==1 && multiline==0) continue;
                            ctmp=0;
                        }
                        strncat(tmp, &c, 1);
                        break;
                }
            }
        }
        
        //for(i = 0; envp[i] != NULL; i++) printf("%s<br>\n", envp[i]); 
        
       //afficherListeVariables(mes_variables);
        libererListeVariables(mes_variables);
        free(tmp);
        free(tmp_tmp);
        for(i=0;ENV[i]!=NULL;i++)
            free(ENV[i]);
        printf("\n");
        return 0;
    
    } else {
        printf("LeeWee by David Lhoumaud\nGnu/GPL\n\nUsage : lw <FILENAME>\nExemple : lw index.cgi\n");
        return 0;
    }

}
