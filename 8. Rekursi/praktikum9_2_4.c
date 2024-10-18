#include <stdio.h>
#include <stdlib.h>

int fibonacci_iterasi(int n);
int fibonacci_rekursi(int n);
int fibonacci_rekursi_tail(int n, int a, int b);

int main()
{
    int pilihan, n, i;

    system("cls");

    do {
        printf("Menu:\n");
        printf("1. Iterasi\n");
        printf("2. Rekursi\n");
        printf("3. Rekursi tail\n");
        printf("4. Keluar\n");
        printf("Pilih metode Fibonacci (1/2/3): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan jumlah bilangan Fibonacci: ");
                scanf("%d", &n);

                printf("Deret Fibonacci: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", fibonacci_iterasi(i));
                }
                printf("\n");
                break;

            case 2:
                printf("Masukkan jumlah bilangan Fibonacci: ");
                scanf("%d", &n);

                printf("Deret Fibonacci: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", fibonacci_rekursi(i));
                }
                printf("\n");
                break;

            case 3:
                printf("Masukkan jumlah bilangan Fibonacci: ");
                scanf("%d", &n);

                printf("Deret Fibonacci: ");
                if (n > 0) {
                    printf("0 ");
                }
                fibonacci_rekursi_tail(n, 0, 1);
                printf("\n");
                break;

            case 4:
                printf("Program selesai\n");
                break;

            default:
                printf("Pilihan tidak tersedia\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}

int fibonacci_iterasi(int n)
{
    int a = 0, b = 1, i, c;

    if (n == 0) {
        return 0;
    }

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int fibonacci_rekursi(int n)
{
    if (n <= 1) {
        return n;
    }

    return fibonacci_rekursi(n - 1) + fibonacci_rekursi(n - 2);
}

int fibonacci_rekursi_tail(int n, int a, int b)
{
    if (n == 0) {
        return b;
    }

    printf("%d ", b);
    return fibonacci_rekursi_tail(n - 1, b, a + b);
}