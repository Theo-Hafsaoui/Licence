#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void Printlist(struct node *Node){
    while (Node!=NULL)
    {
        printf("%d\n",Node->data);
        Node=Node->next;
    }
    
}

void push(struct node** headR, int Ndata) 
{ 
    struct node* Nnode= (struct node*) malloc(sizeof(struct node));
    Nnode->data= Ndata;
    Nnode->next= (*headR);
    (*headR)=Nnode;

}
void del(struct node* node1,int Ddata){
    int t;
    struct node* node=node1;
    node1=node1->next;
    while (node!=NULL)
    {
        if (node1->data==Ddata)
        {
            t=node1->data;
            node->next=node1->next;
        }
        node1=node1->next;
        node=node->next;
    }
    
}
void Max(struct node *Tnode){
    int max;
    max=Tnode->data;
    while (Tnode!=NULL)
    {
        if (Tnode->data>max)
        {
            max=Tnode->data;
        }
    Tnode=Tnode->next; 
    }
    printf("max= %d",max);
    
}

int main(){
    struct node* head=NULL;
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 8); 
    push(&head, 5);
    push(&head, 6);
    printf("liste =\n");
    Printlist(head);
    printf("---------\n");
    del(head,8);
    Printlist(head);
    Max(head);
}

