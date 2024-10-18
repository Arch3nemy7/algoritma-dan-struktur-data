#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *p;

void alokasi();
void akhir();
void hapusAwal();
void hapus_ttt();
void bebaskan(Node *);
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
    puts("Menghapus node posisi tertentu");
    hapus_ttt();
    tampil();

    return 0;
}

void alokasi()
{
    int nilai;

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("Data yang mau dimasukkan : ");
        scanf("%i", &nilai);
        fflush(stdin);
        
        p->data = nilai;
        p->next = NULL;
    }
}

void akhir()
{
    Node *tail;

    if (head == NULL) {
        head = p;
    } else {
        tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = p;
        tail = tail->next;
    }
}

void hapusAwal()
{
    Node *hapus;

    hapus = head;
    if (hapus->next == NULL) {
        bebaskan(hapus);
        head = NULL;
    } else {
        head = hapus->next;
        bebaskan(hapus);
    }
}

void hapus_ttt()
{
    Node *hapus, *phapus;
    int key;

    printf("Masukkan data yang mau dihapus : ");
    scanf("%i", &key);
    fflush(stdin);

    hapus = head;
    if (hapus->data == key) {
        hapusAwal();
    } else {
        while (hapus->data != key) {
            if (hapus->next == NULL) {
                printf("%i Tidak ada di dalam SLL. Exiting", key);
                exit(0);
            } else {
                phapus = hapus;
                hapus = hapus->next;
            }
        }
        phapus->next = hapus->next;
        bebaskan(hapus);
    }
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}

void tampil()
{
    Node *baca;

    baca = head;

    printf("\nData yang ada dalam SLL\n");
    
    while (baca != NULL) {
        printf("%i\n", baca->data);
        baca = baca->next;
    }
}