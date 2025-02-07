#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Dnode;
struct simpul {
    int data;
    Dnode *next;
    Dnode *prev;
};
Dnode *head = NULL, *tail, *p;

void menu();
void alokasi();
void awal();
void akhir();
void after();
void before();
void tampil();

int main()
{
    system("cls");

    do {
        menu();
        tampil();
    } while (1);

    return 0;
}

void menu()
{
    int pil;

    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");
    puts("5. Keluar");

    printf("Masukkan pilihan Anda : ");
    scanf("%i", &pil);
    fflush(stdin);

    switch (pil) {
    case 1:
        alokasi();
        awal();
        break;
    case 2:
        alokasi();
        akhir();
        break;
    case 3:
        alokasi();
        after();
        break;
    case 4:
        alokasi();
        before();
        break;
    case 5:
        printf("Selesai.");
        exit(0);
    default:
        printf("Pilihan tidak ada. Exiting");
        exit(0);
    }
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

void after()
{
    int key;
    Dnode *tail;

    tail = head;

    if (head == NULL) {
        awal();
        return;
    } else {
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
}

void before()
{
    int key;
    Dnode *tail;

    tail = head;

    if (head == NULL) {
        awal();
        return;
    } else {
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