#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
typedef int itemType;

struct simpul {
    itemType data;
    Node *next;
};
Node *head, *p;

void menu();
void inisialisasi();
int isEmpty();
void push();
itemType pop();
void bebaskan(Node *);
void display();

int main()
{
    char jawab;

    system("cls");

    puts("Implementasi Stack dengan Menggunakan Linked Lists");
    
    do {
        menu();
    } while (1);
    
    return 0;
}

void menu()
{
    itemType x;
    int pil;

    puts("Menu Stack");
    puts("1. Mengisi Stack (PUSH)");
    puts("2. Mengambil isi stack (POP)");
    puts("3. Menampilkan isi stack -> LIFO");
    puts("4. Keluar");

    printf("Masukkan pilihan Anda: ");
    scanf("%i", &pil);
    fflush(stdin);

    switch (pil) {
        case 1:
            inisialisasi();
            push();
            break;
        case 2:
            printf("Data yang diambil dari stack adalah %i\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Selesai.");
            exit(0);
        default:
            printf("Pilihan tidak ada. Exiting");
            exit(0);
    }
}

void inisialisasi()
{
    int nilai;

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("Data yang mau dimasukkan: ");
        scanf("%i", &nilai);
        fflush(stdin);

        p->data = nilai;
        p->next = NULL;
    }    
}

int isEmpty()
{
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push()
{
    if (head != NULL) {
        p->next = head;
    }

    head = p;
}

itemType pop()
{
    Node *hapus;
    itemType temp;

    hapus = head;
    
    if (isEmpty() == 1) {
        head = NULL;
        puts("Stack kosong, tidak bisa mengambil data.");
        exit(0);
    } else {
        head = hapus->next;
        temp = hapus->data;
        bebaskan(hapus);
        
        return temp;
    }
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}

void display()
{
    Node *tail;

    if (isEmpty() == 1) {
        printf("Stack kosong!\n");
        return;
    } else {
        tail = head;

        puts("Isi stack: ");
        do {
            printf("%i", tail->data);
            printf("\n");
            tail = tail->next;
        } while (tail->next != NULL);
        while (tail != NULL) {
            printf("%i\n", tail->data);
            tail = tail->next;
        }
        
    }
}