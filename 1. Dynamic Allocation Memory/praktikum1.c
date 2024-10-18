#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;

struct simpul {
    int data;
    Node *next;
};

int main()
{
    Node *head, *tail, *p1, *p2;

    //Node baru (p) awal
    head = NULL;
    p1 = (Node*) malloc(sizeof(Node));
    p1->data = 5;
    p1->next = NULL;
    head = p1;

    //Node baru (p) awal
    p2 = (Node*) malloc(sizeof(Node));
    p2->data = 6;
    p2->next = NULL;

    tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }

    tail->next = p2;

    printf("Nilai pada data baru = %i", p1->data);
    printf("Nilai pada data baru = %i", p2->data);

    return 0;
}