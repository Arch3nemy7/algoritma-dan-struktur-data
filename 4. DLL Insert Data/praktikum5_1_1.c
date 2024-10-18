#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *next;
    Dnode *prev;
};

Dnode *head = NULL, *p;

void alokasi();
void awal();
void tampil();

int main()
{
    char jwb;

    system("cls");

    puts("Double Linked List - Insert di Awal");

    do {
        alokasi();
        awal();
        printf("Lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();
}

void alokasi()
{
    int nilai;
    p = (Dnode *) malloc(sizeof(Dnode));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("Data yang mau dimasukkan : ");
        scanf("%i", &nilai);
        fflush(stdin);

        p->next = NULL;
        p->prev = NULL;
        p->data = nilai;
    }
}

void awal()
{
    if (head != NULL) {
        p->next = head;
        head->prev = p->next;
    }
    head = p;
}

void tampil()
{
    Dnode *baca;

    baca = head;

    printf("\nData yang ada dalam DLL\n");
    
    while (baca != NULL) {
        printf("%i\n", baca->data);
        baca = baca->next;
    }
}