#include <stdio.h>
#include <stdlib.h>

int faktorial(int);
int permutasi(int, int);
int kombinasi(int, int);

int main() {
    int n, r;

    system("cls");

    printf("Masukkan nilai n: ");
    scanf("%i", &n);
    fflush(stdin);

    printf("Masukkan nilai r: ");
    scanf("%i", &r);
    fflush(stdin);

    printf("Permutasi dari %i dan %i adalah %i\n", n, r, permutasi(n, r));
    printf("Kombinasi dari %i dan %i adalah %i\n", n, r, kombinasi(n, r));

    return 0;
}

int faktorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * faktorial(n-1);
    }
}

int permutasi(int n, int r) {
    return faktorial(n) / faktorial(n-r);
}

int kombinasi(int n, int r) {
    return faktorial(n) / (faktorial(r) * faktorial(n-r));
}