#include <stdio.h>
#include <stdlib.h>

int fpb (int, int);

int main()
{
    int a, b;

    system("cls");
    
    printf("Masukkan bilangan pertama: ");
    scanf("%d", &a);
    fflush(stdin);

    printf("Masukkan bilangan kedua: ");
    scanf("%d", &b);
    fflush(stdin);
    
    printf("FPB dari %d dan %d adalah %d\n", a, b, fpb(a,b));

    return 0;
}

int fpb(int x, int y)
{
    int hasil;

    if (y <= x && x % y == 0) {
        return y;
    } else if (x < y) {
        hasil = fpb(y, x);
        return hasil;
    } else {
        hasil = fpb(y, x % y);
        return hasil;
    }
}