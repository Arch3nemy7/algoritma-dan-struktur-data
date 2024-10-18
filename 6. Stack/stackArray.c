#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

void inisialisasi(stack *);
int isFull(stack *);
int isEmpty(stack *);
void push(itemType, stack *);
itemType pop(stack *);

int main()
{
    stack tumpukan;
    char jawab;
    itemType x;

    system("cls");

    puts("Implementasi Stack dengan Menggunakan Array");
    inisialisasi(&tumpukan);
    puts("Mengisi Stack");
    
    do {
        printf("Masukkan elemen yang akan disimpan: ");
        scanf("%c", &x);
        fflush(stdin);
        push(x, &tumpukan);
        printf("Ada data lagi? ");
        jawab = getchar();
        fflush(stdin);
    } while (jawab == 'Y' || jawab == 'y');
    
    puts("");
    
    while (isEmpty(&tumpukan) == 0) {
        printf("%c\n", pop(&tumpukan));
    }

    return 0;
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
    }
}

itemType pop(stack *s)
{
    itemType x;

    if (isEmpty(s) == 1) {
        puts("Stack kosong, tidak ada data.");
        
        return(' ');
    } else {
        x = s->data[--s->count];
        
        return x;
    }
}