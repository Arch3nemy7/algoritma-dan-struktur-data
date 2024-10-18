#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);

int main()
{
    int n;

    system("cls");

    printf("Masukkan jumlah bilangan fibonacci yang ingin ditampilkan: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}

int fibonacci(int n)
{
    int a, b, c;

    a = 0;
    b = 1;

    printf("Bilangan fibonacci: ");
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}