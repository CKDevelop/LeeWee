
typedef struct variable variable;
struct variable
{
    char *name;
    char *value;
    struct variable *next;
};
 
typedef variable* llist;

llist mes_variables = NULL;




llist ajouterVariable(llist liste, char *nom, char *valeur)
{
    /* On crée un nouvel élément */
    variable* nouvelElement = malloc(sizeof(variable));
   //printf("%s",valeur);
    /* On assigne la valeur au nouvel élément */
    asprintf(&nouvelElement->name,nom);
    asprintf(&nouvelElement->value,valeur);
    //nouvelElement->name = nom;
    //nouvelElement->value = valeur;
 
    /* On assigne l'adresse de l'élément suivant au nouvel élément */
    nouvelElement->next = liste;
 
    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return nouvelElement;
}

llist libererListeVariables(llist liste)
{
    variable* tmp = liste;
    variable* tmpnxt;
 
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

llist libererVariable(llist liste, char *nom)
{
    /* Liste vide, il n'y a plus rien à supprimer */
    if(liste == NULL)
        return NULL;
 
    /* Si l'élément en cours de traitement doit être supprimé */
    if(liste->name == nom){
        variable* tmp = liste->next;
        free(liste);
        tmp = libererVariable(tmp, nom);
        return tmp;
    }else{
        liste->next = libererVariable(liste->next, nom);
        return liste;
    }
}

void afficherListeVariables(llist liste)
{
    variable *tmp = liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        //printf("$[%s] == %s\n", tmp->name, tmp->value);
        /* On avance d'une case */
        tmp = tmp->next;
    }
}

char * afficherVariable(llist liste,  char *nom)
{
    variable *tmp=liste;
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
    char *env = getenv(nom);
    if (env == NULL) {
        return "";
    } else { return env; }
}
