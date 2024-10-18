#include <stdio.h>
#include <stdlib.h>

void selection_sort(int [], int, int *, int *);
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

void selection_sort(int arr[], int panjang, int *perbandingan, int *pertukaran)
{
    for (int i = 0; i < panjang - 1; i++) {
        int indeks_min;
        int temp;

        indeks_min =  i;
        
        for (int j = i + 1; j < panjang; j++) {
            (*perbandingan)++;
            
            if (arr[j] < arr[indeks_min]) {
                indeks_min = j;
            }
        }
        
        if (indeks_min != i) {
            (*pertukaran)++;
            temp = arr[i];
            arr[i] = arr[indeks_min];
            arr[indeks_min] = temp;
        }
    }
}

void print_array(int arr[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void sort_dan_print(int arr[], int panjang)
{
    int perbandingan, pertukaran;

    perbandingan = 0;
    pertukaran = 0;
    
    printf("Sebelum sorting: ");
    print_array(arr, panjang);
    
    printf("Setelah sorting: ");
    selection_sort(arr, panjang, &perbandingan, &pertukaran);
    print_array(arr, panjang);

    printf("Jumlah perbandingan: %i\n", perbandingan);
    printf("Jumlah pertukaran: %i\n\n", pertukaran);
}
