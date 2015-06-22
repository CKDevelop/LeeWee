void fill_argv(char *tmp_argv);
char * shell(const char * str);

static char *my_argv[LG_MAX];

void fill_argv(char *tmp_argv)
{
    char *foo = tmp_argv;
    int index = 0;
    char ret[LG_MAX];
    bzero(ret, LG_MAX);
    while(*foo != '\0') {
        if(index == 10)
            break;

        if(*foo == ' ') {
            if(my_argv[index] == NULL)
                my_argv[index] = (char *)malloc(sizeof(char) * strlen(ret) + 1);
            else {
                bzero(my_argv[index], strlen(my_argv[index]));
            }
            strncpy(my_argv[index], ret, strlen(ret));
            strncat(my_argv[index], "\0", 1);
            bzero(ret, LG_MAX);
            index++;
        } else {
            strncat(ret, foo, 1);
        }
        foo++;
        /*printf("foo is %c\n", *foo);*/
    }
    my_argv[index] = (char *)malloc(sizeof(char) * strlen(ret) + 1);
    strncpy(my_argv[index], ret, strlen(ret));
    strncat(my_argv[index], "\0", 1);
}

char * shell(const char * str) {
    FILE *in;
    extern FILE *popen();
    char buff[LG_MAX*100];
    char *output=malloc (sizeof (*output) * LG_MAX);
    
    if (strlen(output)>0) strcpy(output,"");
    if (strlen(buff)>0) strcpy(buff,"");
    
    
    if(!(in = popen(str_strip(str), "r"))){
        exit(1);
    }
    strcpy(output,buff);
/*    int a=0;*/
/*    int npos=-1;*/
    while(fgets(buff, sizeof(buff), in)!=NULL){
/*        if (a>0) {*/
/*            if (a==1 && npos > -1 ) strcat(output,"<br>");*/
/*            str_replace_first(buff,"\n", "<br>");*/
/*        } else {*/
/*            npos=str_istr(buff,"\n");*/
/*        }*/
        //str_replace_first(buff,"   ", "&nbsp;");
        strcat(output,buff);
/*        a++;*/
    }
    pclose(in);
    return output;
}
