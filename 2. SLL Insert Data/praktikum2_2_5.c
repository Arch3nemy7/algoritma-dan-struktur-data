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

Node *head = NULL, *tail, *p;

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

void akhir()
{
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

void after()
{
    int key;

    tail = head;

    printf("Disisipkan setelah nomor berapa ? ");
    scanf("%i", &key);
    fflush(stdin);

    while (tail->no != key){
        if (tail->next == NULL){
            printf("%i tidak ada di dalam SLL\n", key);
            exit(0);
        } else {
            tail = tail->next;
        }
    }

    p->next = tail->next;
    tail->next = p;
}

void before()
{
    int key;
    Node *hand;

    tail = head;

    printf("Disisipkan sebelum nomor berapa ? ");
    scanf("%i", &key);
    fflush(stdin);

    while (tail->no != key){
        if (tail->next == NULL){
            printf("%i tidak ada di dalam SLL\n", key);
            exit(0);
        } else {
            hand = tail;
            tail = tail->next;
        }
    }

    p->next = tail;
    hand->next = p;
}

void tampil()
{
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