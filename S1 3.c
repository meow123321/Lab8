#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int x,int y,struct Node *aux,struct Node *curent)
{
    int i;
    struct Node* newElement=NULL;
    aux->data=1;
    aux->next=NULL;
    curent=aux;

        for(i=0; i<x; i++)
        {
            newElement=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&y);
            newElement->data=y;
            curent->next=newElement;
            newElement->next=NULL;
            curent=newElement;
        }
}

void PrintList(struct Node *node)
{
    if (node==NULL)
        printf ("Empty list!");
    else
    {
        while(node!=NULL)
        {
            printf("%d ", node->data);
            node = node->next;
        }
    }
}

void deleteList(struct Node** head)
{
   struct Node* C = *head;
   struct Node* next;

   while (C != NULL)
   {
       next = C->next;
       free(C);
       C = next;
   }

   *head = NULL;
}

int main()
{
    struct Node* aux=NULL;
    struct Node* curent=NULL;
    int n;
    int m;

    aux=(struct Node*)malloc(sizeof(struct Node));
    curent=(struct Node *)malloc(sizeof(struct Node));

    printf("Enter the number of elements from the list: ");
    scanf("%d",&n);

    printf("Enter the elements from the list: \n");

    createList(n,m,aux,curent);
    PrintList(aux);
    printf("\n");

    deleteList(&aux);
    PrintList(aux);

    return 0;
}
