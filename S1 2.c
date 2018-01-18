#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

int i;
int index;

void getNth ( struct node * p );

int main()
{
    struct node * curent = ( struct node *) malloc( sizeof( struct node) );
    struct node * head;
    struct node * aux;

    curent -> next = NULL;
    head=curent;



    for ( i = 0 ; i < 12 ; i++ )
    {
        aux = ( struct node *) malloc ( sizeof( struct node) );
        aux -> data = rand() % 50;
        aux -> next = NULL;
        curent -> next = aux;
        curent = aux;
    }

    curent = head;
    for ( i = 0 ; i < 12 ; i++ )
    {
        curent = curent -> next;
        printf ( "\n%d", curent -> data);
    }

    printf ( "\nEnter the index position: ");
    scanf ( "%d", &index );

    curent = head;

    getNth ( curent );

    while( head -> next )
    {
        curent = head -> next;
        free( head );
        head = curent;
    }

    return 0;
}

void getNth ( struct node * p )
{
    int i;
    int ok = 1;

    for ( i = 0 ; i < index ; i++ )
    {
        p = p -> next;
        if (i == index)
        {
            ok = 0;
            break;
        }
    }

    if ( ok )
        printf ( "\nThe data value stored in the node at that index position is : %d \n ", p -> data );
    else
        printf ( "\nThe list is shortest then this index! \n ");
}
