
typedef struct marker marker;
struct marker
{
    char *name;
    long value;
    struct marker *next;
};
 
typedef marker* lmarker;

lmarker mes_markers = NULL;

lmarker ajouterMarker(lmarker liste, char *nom, long valeur)
{
    /* On crée un nouvel élément */
    marker* nouvelElement = malloc(sizeof(marker));
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

lmarker libererListeMarkers(lmarker liste)
{
    marker* tmp = liste;
    marker* tmpnxt;
 
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

lmarker libererMarker(lmarker liste, char *nom)
{
    /* Liste vide, il n'y a plus rien à supprimer */
    if(liste == NULL)
        return NULL;
 
    /* Si l'élément en cours de traitement doit être supprimé */
    if(liste->name == nom){
        marker* tmp = liste->next;
        free(liste);
        tmp = libererMarker(tmp, nom);
        return tmp;
    }else{
        liste->next = libererMarker(liste->next, nom);
        return liste;
    }
}

long afficherMarker(lmarker liste,  char *nom)
{
    marker *tmp=liste;
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
