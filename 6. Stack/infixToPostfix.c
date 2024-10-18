#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
} stack;

itemType awal[MAX];

void inisialisasi(stack *);
int isFull(stack *);
int isEmpty(stack *);
void push(itemType, stack *);
void pop(stack *);
void postFix(stack *);
int konversi(itemType);

int main()
{
    itemType jwb;
    stack tumpukan;

    system("cls");

    puts("\tKONVERSI INFIX KE POSTFIX\n");
    puts("");

    do{
        inisialisasi(&tumpukan);
        postFix(&tumpukan);
        fflush(stdin);
        printf("\nCoba lagi (y/t) ? ");
        scanf("%c", &jwb);
        puts(" ");
        fflush(stdin);
    } while (jwb == 'Y' || jwb == 'y');

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

void push(itemType op, stack *s)
{
    if(isFull(s) == 1) {
        puts("\nStack penuh, tidak bisa menambah data lagi.");
    } else {
        fflush(stdin);
        s->data[s->count] = op;
        s->count++;
    }
}

void pop(stack *s)
{
    if(isEmpty(s) == 1) {
        puts("\nStack kosong, tidak ada data.");
    } else {
        s->count--;
        printf("%c ", s->data[s->count]);
    }
}

int konversi(itemType y)
{
    int temp;

    if(y == '^') {
        temp = 3;
    } else if (y == '*') {
        temp = 2;
    } else if (y == '/') {
        temp = 2;
    } else if (y == '+') {
        temp = 1;
    } else if (y == '-') {
        temp = 1;
    } else {
        temp = 0;
    }

    return temp;
}

void postFix(stack *s)
{
    int drjt;
    itemType tampung;

    printf("Masukkan notasi infix: ");
    gets(awal);
    for (int i = 0; i < strlen(awal); i++) {
        tampung = awal[i];

        if(tampung =='+' || tampung == '-' || tampung == '*' || tampung == '/' || tampung == '^') {
            drjt = konversi (tampung);

            if(isEmpty(s) || drjt > konversi(s->data[s->count-1])) {
                push(tampung, s);
            } else {
                while((!isEmpty(s)) || drjt < konversi(s->data[s->count-1]))
                    pop(s);
                push(tampung, s);
            }
        } else if(tampung == '(') {
            push(tampung, s);
        } else if (tampung == ')') {
            while (s->data[s->count-1] !='(')
                pop(s);
                (s->count)--;
        } else if(tampung >= '0' && tampung <= '9')
            printf("%c ", tampung);
    }

    while(!isEmpty(s))
        pop(s);
}