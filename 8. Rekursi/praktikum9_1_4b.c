#include <stdio.h>
#include <stdlib.h>

int faktorial_rekursi(int);

int main()
{
    int n;

    system("cls");
    
    printf("Masukkan bilangan: ");
    scanf("%d", &n);
    
    printf("Faktorial dari %d adalah %d\n", n, faktorial_rekursi(n));
    
    return 0;
}

int faktorial_rekursi(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial_rekursi(n - 1);
    }
}