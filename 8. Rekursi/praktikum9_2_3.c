#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);

int main()
{
    int n;
    
    system("cls");

    printf("Masukkan jumlah bilangan fibonacci yang ingin ditampilkan: ");
    scanf("%d", &n);

    printf("Bilangan fibonacci:\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");

    return 0;
}

int fibonacci(int n)
{
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}