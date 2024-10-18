#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Dnode;
struct siswa {
    int no;
    char nama[100];
    float nilai;
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
    int number;
    char name[100];
    float score;

    p = (Dnode *) malloc(sizeof(Dnode));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("No\t: ");
        scanf("%i", &number);
        fflush(stdin);
        p->no = number;
        

        printf("Nama\t: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
        strcpy(p->nama, name);
        fflush(stdin);
        
        printf("Nilai\t: ");
        scanf("%f", &score);
        fflush(stdin);
        p->nilai = score;

        p->next = NULL;
        p->prev = NULL;
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

    puts("Data yang telah diinputkan :");
    puts("No\tNama\tNilai");

    while (baca != NULL) {
        printf("%i\t", baca->no);
        printf("%s\t", baca->nama);
        printf("%g\t\n", baca->nilai);

        baca = baca->next;
    }
}