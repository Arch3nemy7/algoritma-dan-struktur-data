#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int [], int, int *, int *, int *);
void print_array(int [], int);
void sort_dan_print(int [], int);

int main()
{
    int array1[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int array2[] = {1, 2, 3, 4, 5, 9, 7, 6, 8, 10};
    int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array4[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    system("cls");
    
    sort_dan_print(array1, 10);
    sort_dan_print(array2, 10);
    sort_dan_print(array3, 10);
    sort_dan_print(array4, 10);
    
    return 0;
}

void insertion_sort(int arr[], int panjang, int *perbandingan, int *geser, int *penyisipan) {
    for (int i = 1; i < panjang; i++) {
        int key = arr[i];
        int j = i - 1;
        
        (*penyisipan)++;
        
        while (j >= 0 && arr[j] > key) {
            (*perbandingan)++;
            (*geser)++;
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
        (*geser)++;
    }
}

void print_array(int arr[], int panjang) {
    for (int i = 0; i < panjang; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void sort_dan_print(int arr[], int panjang) {
    int perbandingan, geser, penyisipan;

    perbandingan = 0;
    geser = 0;
    penyisipan = 0;
    
    printf("Sebelum sorting: ");
    print_array(arr, panjang);
    
    printf("Setelah sorting: ");
    insertion_sort(arr, panjang, &perbandingan, &geser, &penyisipan);
    print_array(arr, panjang);
    
    printf("Jumlah perbandingan: %i\n", perbandingan);
    printf("Jumlah pergeseran: %i\n", geser);
    printf("Jumlah penyisipan: %i\n\n", penyisipan);
}
