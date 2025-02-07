#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Dnode;
struct simpul {
    int no;
    char nama[100];
    float nilai;
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
    before();
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
    char jawab;
    Dnode *tail;

    tail = head;

    printf("Ingin memasukkan data sebelum ttt (y/t) ? ");
    jawab = getchar();
    fflush(stdin);

    if (jawab == 'y' || jawab == 'Y'){
        alokasi();

        printf("Disisipkan sebelum nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);

        if (head->no == key) {
            awal();
            return;
        } else {
            while (tail->no != key) {
                if (tail->next == NULL) {
                    printf("%i tidak ada di dalam DLL. Exiting", key);
                    exit(0);
                } else {
                    tail = tail->next;
                }
            }
        }
    } else {
        printf("Selesai.");
        exit(0);
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

    puts("Data yang telah diinputkan :");
    puts("No\tNama\tNilai");

    while (baca != NULL) {
        printf("%i\t", baca->no);
        printf("%s\t", baca->nama);
        printf("%g\t\n", baca->nilai);

        baca = baca->next;
    }
}