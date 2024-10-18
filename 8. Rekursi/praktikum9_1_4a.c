#include <stdio.h>
#include <stdlib.h>

int faktorial_iterasi(int);

int main()
{
    int n;

    system("cls");
    
    printf("Masukkan bilangan: ");
    scanf("%d", &n);
    
    printf("Faktorial dari %d adalah %d\n", n, faktorial_iterasi(n));
    
    return 0;
}

int faktorial_iterasi(int n)
{
    int faktorial = 1;

    for (int i = 1; i <= n; i++) {
        faktorial = faktorial * i;
    }
    
    return faktorial;
}