#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long faktorial_iterasi(int);
long long faktorial_rekursi(int);
long long faktorial_rekursi_tail(int, long long);

int main()
{
    int n, pilihan;
    clock_t awal, akhir;
    double waktu_dibutuhkan;

    system("cls");
    
    printf("Menu faktorial:\n");
    printf("1. Iterasi\n");
    printf("2. Rekursi\n");
    printf("3. Rekursi tail\n");
    printf("Pilih metode faktorial (1/2/3): ");
    scanf("%d", &pilihan);
    
    printf("Masukkan bilangan: ");
    scanf("%d", &n);
    
    switch (pilihan) {
        case 1:
            awal = clock();
            printf("Faktorial dari %i adalah %lld\n", n, faktorial_iterasi(n));
            akhir = clock();
            waktu_dibutuhkan = ((double) (akhir - awal)) / CLOCKS_PER_SEC;
            printf("Waktu komputasi: %f detik\n", waktu_dibutuhkan);  
            break;
        case 2:
            awal = clock();
            printf("Faktorial dari %i adalah %lld\n", n, faktorial_rekursi(n));
            akhir = clock();
            waktu_dibutuhkan = ((double) (akhir - awal)) / CLOCKS_PER_SEC;
            printf("Waktu komputasi: %f detik\n", waktu_dibutuhkan);  
            break;
        case 3:
            awal = clock();
            printf("Faktorial dari %i adalah %lld\n", n, faktorial_rekursi_tail(n, 1));
            akhir = clock();
            waktu_dibutuhkan = ((double) (akhir - awal)) / CLOCKS_PER_SEC;
            printf("Waktu komputasi: %f detik\n", waktu_dibutuhkan);  
            break;
        default:
            printf("Pilihan tidak ada. Exiting.\n");
    }
    
    return 0;
}


long long faktorial_iterasi(int n)
{
    long long faktorial = 1;
    
    for (int i = 1; i <= n; i++) {
        faktorial = faktorial * i;
    }

    return faktorial;
}

long long faktorial_rekursi(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial_rekursi(n - 1);
    }
}

long long faktorial_rekursi_tail(int n, long long hasil)
{
    if (n == 0) {
        return hasil;
    } else {
        return faktorial_rekursi_tail(n - 1, n * hasil);
    }
}
