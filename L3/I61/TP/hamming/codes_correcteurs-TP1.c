#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct Bulle Bulle;
struct Bulle
{
    int ele;
    Bulle* next;
};


void affiche_bulle(Bulle* b, int n){
    int el;
    printf("[");
    for (int i=0; i<n-1; i++) {
        el=b->ele;
        printf("%d,",el);
        b=b->next;
    }
    printf("%d]\n",b->ele);
}

Bulle* Gen_Tab(int n, int modulo)
{
    Bulle* head = malloc(sizeof(Bulle));
    head -> ele = rand() % modulo;
    head -> next = NULL;
    Bulle* last_bubul= head;
    for (int c=0; c<n; c++)
    {
        Bulle* tail_bubule = malloc(sizeof(Bulle));
        tail_bubule-> ele = rand() % modulo;
        tail_bubule -> next = NULL;
        //JE RACCROCHE LES DEUX BOITES DE CHAQUE COTÉE
        last_bubul->next=tail_bubule;
        last_bubul=tail_bubule;
    }
    affiche_bulle(head, 5);
    return head;
}

int main (int argc, char *argv[])
{
    srand(time(NULL));
    Gen_Tab(5,10);
    return 0;
}
