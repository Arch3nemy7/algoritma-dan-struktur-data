#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *next;
    Dnode *prev;
};
Dnode *head, *p;

void alokasi();
void akhir();
void hapusAwal();
void bebaskan(Dnode *);
void tampil();


int main()
{
    char jwb;

    system("cls");

    do {
        alokasi();
        akhir();
        printf("Lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();
    puts("Menghapus node pertama");
    hapusAwal();
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

void hapusAwal()
{
    Dnode *hapus;

    hapus = head;

    if (head->next == NULL) {
        head = NULL;
    } else {
        head = hapus->next;
        head->prev = NULL;
    }
    
    bebaskan(hapus);
}

void bebaskan(Dnode *x)
{
    free(x);
    x = NULL;
}

void tampil()
{
    Dnode *baca;

    baca = head;

    while (baca != NULL) {
        printf("%i\n", baca->data);
        baca = baca->next;
    }
}