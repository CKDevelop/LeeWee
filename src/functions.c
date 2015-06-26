
typedef struct fonctions fonctions;
struct fonctions
{
    char *name;
    long value;
    struct fonctions *next;
};
 
typedef fonctions* lfonctions;

lfonctions mes_fonctions = NULL;

lfonctions ajouterFonction(lfonctions liste, char *nom, long valeur)
{
    /* On crée un nouvel élément */
    fonctions* nouvelElement = malloc(sizeof(fonctions));
   //printf("%s",valeur);
    /* On assigne la valeur au nouvel élément */
    asprintf(&nouvelElement->name,nom);
    //asprintf(&nouvelElement->value,valeur);
    //nouvelElement->name = nom;
    nouvelElement->value = valeur;
 
    /* On assigne l'adresse de l'élément suivant au nouvel élément */
    nouvelElement->next = liste;
 
    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return nouvelElement;
}

lfonctions libererListeFonctionS(lfonctions liste)
{
    fonctions* tmp = liste;
    fonctions* tmpnxt;
 
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On stocke l'élément suivant pour pouvoir ensuite avancer */
        tmpnxt = tmp->next;
        /* On efface l'élément courant */
        free(tmp);
        /* On avance d'une case */
        tmp = tmpnxt;
    }
    /* La liste est vide : on retourne NULL */
    return NULL;
}

lfonctions libererFonction(lfonctions liste, char *nom)
{
    /* Liste vide, il n'y a plus rien à supprimer */
    if(liste == NULL)
        return NULL;
 
    /* Si l'élément en cours de traitement doit être supprimé */
    if(liste->name == nom){
        fonctions* tmp = liste->next;
        free(liste);
        tmp = libererFonction(tmp, nom);
        return tmp;
    }else{
        liste->next = libererFonction(liste->next, nom);
        return liste;
    }
}

long afficherFonction(lfonctions liste,  char *nom)
{
    fonctions *tmp=liste;
    /* Tant que l'on n'est pas au bout de la liste */
                                
    while(tmp != NULL)
    {
        
        if(strcmp(tmp->name,nom)==0)
        {
            //printf("--%s == %s\n",tmp->name, tmp->value);
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return 0;
}

/* END FUNCTION */

typedef struct endfonctions endfonctions;
struct endfonctions
{
    char *name;
    long value;
    struct endfonctions *next;
};
 
typedef endfonctions* lendfonctions;

lendfonctions mes_endfonctions = NULL;

lendfonctions ajouterEndFonction(lendfonctions liste, char *nom, long valeur)
{
    /* On crée un nouvel élément */
    endfonctions* nouvelElement = malloc(sizeof(endfonctions));
   //printf("%s",valeur);
    /* On assigne la valeur au nouvel élément */
    asprintf(&nouvelElement->name,nom);
    //asprintf(&nouvelElement->value,valeur);
    //nouvelElement->name = nom;
    nouvelElement->value = valeur;
 
    /* On assigne l'adresse de l'élément suivant au nouvel élément */
    nouvelElement->next = liste;
    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return nouvelElement;
}

lendfonctions libererListeEndFonctionS(lendfonctions liste)
{
    endfonctions* tmp = liste;
    endfonctions* tmpnxt;
 
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On stocke l'élément suivant pour pouvoir ensuite avancer */
        tmpnxt = tmp->next;
        /* On efface l'élément courant */
        free(tmp);
        /* On avance d'une case */
        tmp = tmpnxt;
    }
    /* La liste est vide : on retourne NULL */
    return NULL;
}

lendfonctions libererEndFonction(lendfonctions liste, char *nom)
{
    /* Liste vide, il n'y a plus rien à supprimer */
    if(liste == NULL)
        return NULL;
 
    /* Si l'élément en cours de traitement doit être supprimé */
    if(liste->name == nom){
        endfonctions* tmp = liste->next;
        free(liste);
        tmp = libererEndFonction(tmp, nom);
        return tmp;
    }else{
        liste->next = libererEndFonction(liste->next, nom);
        return liste;
    }
}

long afficherEndFonction(lendfonctions liste,  char *nom)
{
    endfonctions *tmp=liste;
    /* Tant que l'on n'est pas au bout de la liste */
                                
    while(tmp != NULL)
    {
        
        if(strcmp(tmp->name,nom)==0)
        {
            //printf("--%s == %s\n",tmp->name, tmp->value);
            /* Si l'élément a la valeur recherchée, on renvoie son adresse */
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return 0;
}
