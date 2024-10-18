#include <stdio.h>
#include <stdlib.h>

void tampil(int);

int main()
{
    int x;

    system("cls");

    printf("Masukkan angka: ");
    scanf("%i", &x);
    tampil(x);

    return 0;
}

void tampil(int x)
{
    if(x < 0) {
        return;
    } else {
        printf("%i\n", x);
        tampil(x-1);
    }
}