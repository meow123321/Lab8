#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n, struct node *aux,struct node *curent)
{
    int y;
    int i;
    struct node* newElement=NULL;

    aux->data=y;
    aux->next=NULL;
    curent=aux;

        for(i=0; i<n; i++)
        {
            newElement=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&y);
            newElement->data=y;
            curent->next=newElement;
            newElement->next=NULL;
            curent=newElement;
        }
}

void PrintList(struct node *head)
{
    if (head==NULL)
        printf("\n Empty list!");
    else
    {
        while(head!=NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
    }
}

int Count(int number,struct node *head)
{
    int count=0;

    while(head!=NULL)
    {
        if(head->data==number)
            count++;

        head=head->next;
    }

    return count;
}

int main()
{
    struct node* aux=NULL;
    struct node* curent=NULL;
    int n;
    int i;
    int search;

    aux=(struct node*)malloc(sizeof(struct node));
    curent=(struct node *)malloc(sizeof(struct node));


    printf("Enter the number of elements from the list: ");
    scanf("%d",&n);

    printf("Enter the elements from the list: \n");

    createList(n,aux,curent);


    printf("Enter the number you want to count: ");
    scanf("%d",&search);

    printf("The number of times %d occurs in the list is: %d",search,Count(search,aux));


    return 0;
}
