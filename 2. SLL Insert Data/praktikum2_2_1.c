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
void awal();
void tampil();

int main()
{
    char jwb;

    system("cls");

    do {
        alokasi();
        awal();
        printf("Ada data lagi (y/t) ? ");
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

void awal()
{
    if (head != NULL) {
        p->next = head;
    }
    
    head = p;
}

void tampil()
{
    Node *tail;

    tail = head;

    puts("Data yang telah diinputkan :");
    puts("No\tNama\tNilai");

    while (tail != NULL) {
        printf("%i\t", tail->no);
        printf("%s\t", tail->nama);
        printf("%g\t\n", tail->nilai);

        tail = tail->next;
    }
}