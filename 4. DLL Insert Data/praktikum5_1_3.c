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
void after();
void tampil();

int main()
{
    char jwb;

    system("cls");

    puts("Double Linked List - Insert After");

    do {
        alokasi();
        akhir();
        printf("Lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();
    alokasi();
    after();
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

void after()
{
    int key;
    Dnode *tail;

    tail = head;

    printf("Disisipkan setelah node berapa? ");
    scanf("%i", &key);
    fflush(stdin);

    while (tail->data != key) {
        if (tail->next == NULL) {
            printf("%i tidak ada di dalam DLL. Exiting", key);
            exit(0);
        } else {
            tail = tail->next;
        }
    }

    if (tail->next != NULL) {
        p->next = tail->next;
        tail->next->prev = p;
    }
    
    p->prev = tail;
    tail->next = p;
}

void tampil()
{
    Dnode *baca;

    baca = head;

    printf("\nData yang ada dalam SLL\n");
    
    while (baca != NULL) {
        printf("%i\n", baca->data);
        baca = baca->next;
    }
}