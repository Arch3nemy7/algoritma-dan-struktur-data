#include <stdio.h>
#include <math.h>

int cek_prima(int, int);

int main()
{
    int n;

    printf("Masukkan sebuah angka: ");
    scanf("%d", &n);
    
    if (n == 1) {
        printf("1 bukan bilangan prima\n");
    } else if (cek_prima(n, 2) == 1) {
        printf("%d adalah bilangan prima\n", n);
    } else {
        printf("%d bukan bilangan prima\n", n);
    }

    return 0;
}

int cek_prima(int n, int i)
{
    if (i > sqrt(n)) {
        return 1;
    }

    if (n % i == 0) {
        return 0;
    }

    return cek_prima(n, i + 1);
}
