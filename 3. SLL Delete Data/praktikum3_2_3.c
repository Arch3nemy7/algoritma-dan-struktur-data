#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa Node;
struct siswa {
    int no;
    char nama[100];
    float nilai;
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
    puts("Menghapus node tertentu");
    hapus_ttt();
    tampil();

    return 0;
}

void alokasi()
{
    int number;
    char name[100];
    float score;

    p = (Node *) malloc(sizeof(Node));

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
    if (hapus->no == key) {
        hapusAwal();
    } else {
        while (hapus->no != key) {
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

    puts("Data yang telah diinputkan :");
    puts("No\tNama\tNilai");

    while (baca != NULL) {
        printf("%i\t", baca->no);
        printf("%s\t", baca->nama);
        printf("%g\t\n", baca->nilai);

        baca = baca->next;
    }
}