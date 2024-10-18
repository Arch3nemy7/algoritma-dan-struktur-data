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
void hapusAkhir();
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
    puts("Menghapus node terakhir");
    hapusAkhir();
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

void hapusAkhir()
{
    Node *hapus, *phapus;

    hapus = head;

    if (hapus->next == NULL) {
        head = NULL;
    } else {
        while (hapus->next != NULL) {
            phapus = hapus;
            hapus = hapus->next;
        }

        phapus->next = NULL;
    }
    bebaskan(hapus);
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