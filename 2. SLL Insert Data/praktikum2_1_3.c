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
void after();
void tampil();

int main()
{
    char jwb;

    system("cls");

    puts("Single Linked List - Insert After");

    do {
        alokasi();
        akhir();
        printf("Lagi (y/t)? ");
        jwb = getchar();
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');

    tampil();
    alokasi();
    after();
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

void after()
{
    int key;
    Node *tail;

    tail = head;

    printf("Disisipkan setelah node berapa ? ");
    scanf("%i", &key);
    fflush(stdin);
    
    while (tail->data != key) {
        if (tail->next == NULL) {
            printf("%i tidak ada di dalam SLL\n", key);
            exit(0);
        } else {
            tail = tail->next;
        }
    }

    p->next = tail->next;
    tail->next = p;  
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
