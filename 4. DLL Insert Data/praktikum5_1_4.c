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
void akhir();
void before();
void tampil();

int main()
{
    char jwb;

    system("cls");

    puts("Double Linked List - Insert Before");

    do {
        alokasi();
        akhir();
        printf("Lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();
    alokasi();
    before();
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

void awal()
{
    if (head != NULL) {
        p->next = head;
        head->prev = p->next;
    }
    head = p;
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

void before()
{
    int key;
    Dnode *tail;

    tail = head;

    printf("Disisipkan sebelum node berapa? ");
    scanf("%i", &key);
    fflush(stdin);

    if (head->data == key) {
        awal();
        return;
    } else {
        while (tail->data != key) {
            if (tail->next == NULL) {
                printf("%i tidak ada di dalam DLL. Exiting", key);
                exit(0);
            } else {
                tail = tail->next;
            }
        }
    }

    p->next = tail;
    p->prev = tail->prev;
    
    tail->prev->next = p;
    tail->prev = p;
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