#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void menu(stack *);
void inisialisasi(stack *);
int isFull(stack *);
int isEmpty(stack *);
void push(itemType, stack *);
itemType pop(itemType, stack *);
void display(stack *);

int main()
{
    stack tumpukan;

    system("cls");

    puts("Implementasi Stack dengan Menggunakan Array");
    inisialisasi(&tumpukan);
    
    do {
        menu(&tumpukan);
    } while (1);

    return 0;
}

void menu(stack *s)
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
            printf("Masukkan elemen yang akan disimpan: ");
            scanf("%c", &x);
            fflush(stdin);
            push(x, s);
            break;
        case 2:
            printf("Data yang diambil dari stack adalah %c\n", pop(x, s));
            break;
        case 3:
            display(s);
            break;
        case 4:
            printf("Selesai.");
            exit(0);
        default:
            printf("Pilihan tidak ada. Exiting");
            exit(0);
    }
}

void inisialisasi(stack *s)
{
    s->count = 0;    
}

int isFull(stack *s)
{
    if (s->count == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(stack *s)
{
    if (s->count == 0) {
        return 1;
    } else {
        return 0;
    }
}

void push(itemType x, stack *s)
{
    if (isFull(s) == 1) {
        puts("Stack penuh, tidak bisa menambah data lagi.");
        return;
    } else {
        s->data[s->count] = x;
        s->count++;
        printf("\n");
    }
}

itemType pop(itemType x, stack *s)
{
    if (isEmpty(s) == 1) {
        puts("Stack kosong, tidak ada data.");
        return(' ');
    } else {
        s->count--;
        x = s->data[s->count];
        
        return x;
    }
}

void display(stack *s)
{
    if (isEmpty(s) == 1) {
        printf("Stack kosong!\n");
        return;
    } else {
        printf("Isi stack: ");
        for (int i = 0; i <= s->count; i++) {
            printf("%c", s->data[i]);
            printf("\n");
        }
    }
    printf("\n\n");
}