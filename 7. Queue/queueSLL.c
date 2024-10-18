#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char itemType;
typedef struct simpul Node;
struct simpul {
    itemType data;
    Node *next;
};

typedef struct {
    Node *front;
    Node *rear;
} queue;
queue *q;
Node *head, *p;

void inisialisasi();
int isEmpty();
void enqueue();
itemType dequeue();

int main()
{

    return 0;
}

void inisialisasi()
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty()
{
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue()
{
    int nilai; 

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting.");
        exit(0);
    } else {
        printf("Masukkan elemen yang akan disimpan: ");
        scanf("%c", &nilai);

        p->data = nilai;
        p->next = NULL;

        if (q->rear == NULL) {
            q->rear = p;
            q->front = p;
        }

        q->rear->next = p;
        q->rear = p;
    }
}

itemType dequeue()
{
    
}