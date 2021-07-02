#include <stdio.h>

int main(){
    char ch;
    ex2 * fopen()

    do {
        printf("Entrez le caractère :");
        ch=getc(stdin);
        putc(ch, stdout);
    } while (ch !='n');
}

int main(void)
{
    int ch;
    FILE *f;
    f = fopen("mes_caracteres.txt", "w");
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
 
    do {
    ch=getc(stdin);
    fputc(ch, f);

    } while((ch!='\n'));
 
    fclose(f);
 
    return 0;
}


partie lecture :
#include<stdio.h>
#include<stdlib.h>
 
int main(void)
{
    FILE* fichier = NULL;
    int caractereActuel = 0;
 
    fichier = fopen("mes_cart.txt", "r");
 
    if (fichier != NULL)
    {
        do
        {
            caractereActuel = fgetc(fichier); 
       
            printf("%c", caractereActuel); 
        } while (caractereActuel != EOF); 

 
        fclose(fichier);
    }
 
    return 0;
}