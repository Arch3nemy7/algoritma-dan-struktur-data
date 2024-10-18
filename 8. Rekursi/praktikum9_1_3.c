#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99

void reverse(char [], int);

int main()
{
    char str[MAX];
    int length;

    system("cls");
    
    printf("Masukkan sebuah string: ");
    fgets(str, sizeof(str), stdin);
    fflush(stdin);
    
    length = strlen(str) - 1;

    reverse(str, length);
    printf("\n");
    return 0;
}

void reverse(char str[], int length)
{
    if (length < 0) {
        return;
    } else {
        printf("%c", str[length--]);
        reverse(str, length);
    }
}