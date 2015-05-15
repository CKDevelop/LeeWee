#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef H_STRING
#define H_STRING

#include <string.h>

/* Redefinition des fonctions standards pour un usage futur, par exemple verifier
   la validite des arguments. */
#define str_cpy  strcpy
#define str_ncpy strncpy
#define str_cat  strcat
#define str_ncat strncat
#define str_cmp  strcmp
#define str_ncmp strncmp
#define str_len  strlen
#define str_chr  strchr
#define str_rchr strrchr
#define str_str  strstr
#define str_spn  strspn
#define str_pbrk strpbrk
#define str_tok  strtok

#define LG_MAX 40960

char hex2dec(char, char);
void urldecode (char *);
int ParseCGIString(char *,char *);
void BeforePrintingCGIString(char *);
char *str_tolower (const char *);
char *str_toupper (const char *);
int str_istr (const char *, const char *);
char *str_sub (const char *, unsigned int, unsigned int);
char **str_split (char *, const char *);
char *str_join (char *, ...);
char *str_replace (const char *, unsigned int, unsigned int, const char *);
void str_replace_first(char * buffer, char * s, char * by);
char *str_strip (const char *);
unsigned short u_getc(FILE *stream, char *bytes);

#endif /* not H_STRING */


/* Convertit un nombre hexadecimal a deux "chiffres" en un caractere usuel */
char hex2dec(char s0, char s1) {
    int sum;
    if ((s1>=48)&&(s1<=57)) /* chiffre */
        sum=s1-48;
    else /* lettre */
        sum=s1-55;
    if ((s0>=48)&&(s0<=57)) /* chiffre */
        sum+=(s0-48)*16;
    else /* lettre */
        sum+=(s0-55)*16;
    return sum;
}

/* Remplace les "+" et les "%xx" de la chaine CGI */
void urldecode(char *src)
{
	int iSrc=0; 
    int iDest=0; 
    do {
        while ((src[iSrc])&&(src[iSrc]!='%'))
            if (src[iSrc]!='+')
                src[iDest++]=src[iSrc++];
            else { 
                src[iDest++]=' ';
                iSrc++;
            } 

        if (src[iSrc]){
            src[iDest++]=hex2dec(src[iSrc+1],src[iSrc+2]);
            iSrc+=3; 
        }
    } while (src[iSrc]);
    src[iDest]=0; 
}

/* Decoupe la chaine CGI en ses differents arguments */
int ParseCGIString(char *pszCGIString,char *pszResult) {
    char pszTemp[LG_MAX], *pszString, *pszPointer;
    int iLength;

    iLength=strlen(pszCGIString);
    if(iLength>0 && iLength<LG_MAX){
        pszString=pszCGIString;
        pszPointer=pszTemp;
        if(*pszString!=0){
            if(*pszString=='=' && *(pszString+1)==0){
                pszString++;
                *pszResult=0;
            }
            while(*pszString!='=' && *pszString!='&' && *pszString!=0) *(pszPointer++)=*(pszString++);
            if(*pszString=='=' || *pszString=='&' || (*pszString==0 && pszPointer!=pszTemp)){
                *pszPointer=0;
                pszPointer=pszTemp;
                if(*pszString && !(*pszString=='=' && *(pszString+1)==0)) pszString++;
                urldecode(pszTemp);
                strcpy(pszResult,pszTemp);
            }
        }
        strcpy(pszCGIString,pszString);
        return 1;
    }else{
        if(iLength>0) printf("Erreur : taille de chaine %d superieure a la longueur max %d. \n",iLength,LG_MAX);
        return 0;
    }
}

/* Remplace les '<' et '>' de la chaine en vue de l'affichage dans un browser */
void BeforePrintingCGIString(char *pszString){
    char pszTemp[LG_MAX];
    int iSrc, iDest;

    iSrc=0;
    iDest=0;
    while(pszString[iSrc]!=0 && iDest<LG_MAX){
        while(pszString[iSrc]!='<' && pszString[iSrc]!='>' && pszString[iSrc]!=0 && iDest<LG_MAX)
            pszTemp[iDest++]=pszString[iSrc++];

        if(pszString[iSrc]=='<'){
            iSrc++;
            if(iDest<(LG_MAX-5)){
                pszTemp[iDest++]='&';
                pszTemp[iDest++]='#';
                pszTemp[iDest++]='6';
                pszTemp[iDest++]='0';
            }
        }
        if(pszString[iSrc]=='>'){
            iSrc++;
            if (iDest<(LG_MAX-5)) {
                pszTemp[iDest++]='&';
                pszTemp[iDest++]='#';
                pszTemp[iDest++]='6';
                pszTemp[iDest++]='2';
            }
        }
    }
    pszTemp[iDest]=0;
    strcpy(pszString,pszTemp);
}

char *str_tolower (const char *ct)
{
  char *s = NULL;

  if (ct != NULL)
  {
    int i;

    s = malloc (sizeof (*s) * (strlen (ct) + 1));
    if (s != NULL)
    {
      for (i = 0; ct[i]; i++)
      {
        s[i] = tolower (ct[i]);
      }
      s[i] = '\0';
    }
  }
  return s;
}

char *str_toupper (const char *ct)
{
  char *s = NULL;

  if (ct != NULL)
  {
    int i;

    s = malloc (sizeof (*s) * (strlen (ct) + 1));
    if (s != NULL)
    {
      for (i = 0; ct[i]; i++)
      {
        s[i] = toupper (ct[i]);
      }
      s[i] = '\0';
    }
  }
  return s;
}

int str_istr (const char *cs, const char *ct)
{
  int index = -1;

  if (cs != NULL && ct != NULL)
  {
    char *ptr_pos = NULL;

    ptr_pos = strstr (cs, ct);
    if (ptr_pos != NULL)
    {
      index = ptr_pos - cs;
    }
  }
  return index;
}

char *str_sub (const char *s, unsigned int start, unsigned int end)
{
  char *new_s = NULL;

  if (s != NULL && start < end)
  {
    new_s = malloc (sizeof (*new_s) * (end - start + 2));
    if (new_s != NULL)
    {
      int i;

      for (i = start; i <= end; i++)
      {
        new_s[i-start] = s[i];
      }
      new_s[i-start] = '\0';
    }
    else
    {
      fprintf (stderr, "Memoire insuffisante\n");
      exit (EXIT_FAILURE);
    }
  }
  return new_s;
}

char **str_split (char *s, const char *ct)
{
  char **tab = NULL;

  if (s != NULL && ct != NULL)
  {
    int i;
    char *cs = NULL;
    size_t size = 1;

    for (i = 0; (cs = strtok (s, ct)); i++)
    {
      if (size <= i + 1)
      {
        void *tmp = NULL;

        size <<= 1;
        tmp = realloc (tab, sizeof (*tab) * size);
        if (tmp != NULL)
        {
          tab = tmp;
        }
        else
        {
          fprintf (stderr, "Memoire insuffisante\n");
          free (tab);
          tab = NULL;
          exit (EXIT_FAILURE);
        }
      }
      tab[i] = cs;
      s = NULL;
    }
    tab[i] = NULL;
  }
  return tab;
}

char *str_join (char *cs, ...)
{
  va_list va;
  const char *ct;
  char *s = NULL;
  size_t size = 0;

  va_start (va, cs);
  while ((ct = va_arg (va, char *)) != NULL)
  {
    void *tmp = NULL;

    size += strlen (ct) + strlen (cs);
    tmp = realloc (s, sizeof (*s) * (size + 1));
    if (tmp != NULL)
    {
      if (s == NULL)
      {
        s = tmp;
        strcpy (s, ct);
      }
      else
      {
         s = tmp;
         strcat (s, cs);
         strcat (s, ct);
      }
    }
    else
    {
      fprintf (stderr, "Memoire insuffisante\n");
      free (s);
      s = NULL;
      exit (EXIT_FAILURE);
    }
  }
  return s;
}

char *str_replace (const char *s, unsigned int start, unsigned int lenght, const char *ct)
{
  char *new_s = NULL;

  if (s != NULL && ct != NULL && start >= 0 && lenght > 0)
  {
    size_t size = strlen (s);

    new_s = malloc (sizeof (*new_s) * (size - lenght + strlen (ct) + 1));
    if (new_s != NULL)
    {
      memcpy (new_s, s, start);
      memcpy (&new_s[start], ct, strlen (ct));
      memcpy (&new_s[start + strlen (ct)], &s[start + lenght], size - lenght - start + 1);
    }
  }
  else
  {
    fprintf (stderr, "Memoire insuffisante\n");
    exit (EXIT_FAILURE);
  }
  return new_s;
}

void str_replace_first(char * buffer, char * s, char * by)
{
    char * p = strstr(buffer, s);
    //char * ret = NULL;
 
    if (p != NULL)
    {
        size_t len_p = strlen(p), len_s = strlen(s), len_by = strlen(by);
 
        if (len_s != len_by)
        {
            /* ajuster la taille de la partie 's' pur pouvoir placer by */
            memmove(p + len_by, p + len_s, len_p);
        }
 
        /* rempacer s par by */
        strncpy(p, by, len_by);
        //ret = buffer;
    }
}

char *str_strip (const char *string)
{
  char *strip = NULL;

  if (string != NULL)
  {
    strip = malloc (sizeof (*strip) * (strlen (string) + 1));
    if (strip != NULL)
    {
      int i, j;
      int ps = 0;

      for (i = 0, j = 0; string[i]; i++)
      {
        if (string[i] == ' ')
        {
          if (ps == 0)
          {
            strip[j] = string[i];
            ps = 1;
            j++;
          }
        }
        else
        {
          strip[j] = string[i];
          ps = 0;
          j++;
        }
      }
      strip[j] = '\0';
    }
    else
    {
      fprintf (stderr, "Memoire insuffisante\n");
      exit (EXIT_FAILURE);
    }
  }
  return strip;
}
