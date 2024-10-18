#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    int data;
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
        
    if (head == NULL) {
        awal();
        return;
    } else {
        printf("Disisipkan setelah nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);
        
        while (tail->data != key){
            if (tail->next == NULL){
                printf("%i tidak ada di dalam SLL\n", key);
                exit(0);
            } else {
                tail = tail->next;
            }
        }
    }

    p->next = tail->next;
    tail->next = p;
}

void before()
{
    int key;
    Node *pbef, *bef;

    bef = head;

    if (head == NULL) {
        awal();
        return;
    } else {
        printf("Disisipkan sebelum nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);

        if (head->data == key) {
            awal();
            return;
        } else {
            while (bef->data != key){
                if (bef->next == NULL){
                    printf("%i tidak ada di dalam SLL\n", key);
                    exit(0);
                } else {
                    pbef = bef;
                    bef = bef->next;
                }
            }
        }
    }

    p->next = bef;
    pbef->next = p;
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