#include <stdio.h>
#include <stdlib.h>

int faktorial_rekursi_tail(int, int);

int main()
{
    int n;

    system("cls");
    
    printf("Masukkan bilangan: ");
    scanf("%d", &n);
    
    printf("Faktorial dari %d adalah %d\n", n, faktorial_rekursi_tail(n, 1));
    
    return 0;
}

int faktorial_rekursi_tail(int n, int hasil)
{
    if (n == 0) {
        return hasil;
    } else {
        return faktorial_rekursi_tail(n - 1, n * hasil);
    }
}