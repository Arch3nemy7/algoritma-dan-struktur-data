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
void akhir();
void tampil();

int main()
{
    char jwb;

    system("cls");

    puts("Double Linked List - Insert di Akhir");

    do {
        alokasi();
        akhir();
        printf("Lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();

    return 0;
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

void akhir()
{
    Dnode *tail;

    tail = head;

    if (head == NULL) {
        head = p;
    } else {
        while (tail->next != NULL) {
            tail = tail->next;
        }

        p->prev = tail;
        tail->next = p;
        tail = p;
    }
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