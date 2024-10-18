#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
typedef int itemType;

struct simpul {
    itemType data;
    Node *next;
};
Node *head, *p;

void inisialisasi();
int isEmpty();
void push();
itemType pop();
void bebaskan(Node *);

int main()
{
    char jawab;

    system("cls");

    puts("Implementasi Stack dengan Menggunakan Linked List");
    
    do {
        inisialisasi();
        push();
        printf("Ada data lagi? ");
        jawab = getchar();
        fflush(stdin);
    } while (jawab == 'Y' || jawab == 'y');

    while (isEmpty() == 0) {
        printf("%i\n", pop());
    }
    
    return 0;
}

void inisialisasi()
{
    int nilai;

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("Data yang mau dimasukkan: ");
        scanf("%i", &nilai);
        fflush(stdin);

        p->data = nilai;
        p->next = NULL;
    }    
}

int isEmpty()
{
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push()
{
    if (head != NULL) {
        p->next = head;
    }

    head = p;
}

itemType pop()
{
    Node *hapus;
    itemType temp;

    hapus = head;
    
    if (isEmpty() == 1) {
        head = NULL;
        puts("Stack kosong, tidak bisa mengambil data.");
        exit(0);
    } else {
        head = hapus->next;
        temp = hapus->data;
        bebaskan(hapus);
        
        return temp;
    }
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}