#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

void generate_random_array(int [], int);
void bubble_sort(int [], int);
void shell_sort(int [], int);
void print_array(int [], int);

int main()
{
    int data[MAX_SIZE], comparison, swapping, movement;

    system("cls");

    srand(time(NULL));
    generate_random_array(data, MAX_SIZE);

    printf("Data awal:\n");
    print_array(data, MAX_SIZE);

    bubble_sort(data, MAX_SIZE);
    shell_sort(data, MAX_SIZE);

    return 0;
}

void generate_random_array(int arr[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        arr[i] = rand() % 1000;
    }
}

void bubble_sort(int arr[], int panjang)
{
    int comparison, swapping, movement;

    comparison = 0;
    swapping = 0;
    movement = 0;

    printf("\nData setelah Bubble Sort:\n");

    for (int i = 0; i < panjang - 1; i++) {
        int flag = 0;
        for (int j = 0; j < panjang - i - 1; j++) {
            comparison++;
            if (arr[j] > arr[j + 1]) {
                swapping++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    print_array(arr, panjang);
    printf("Jumlah pembandingan: %i\n", comparison);
    printf("Jumlah penukaran: %i\n", swapping);
    printf("Jumlah pergeseran: %i\n", movement);
}

void shell_sort(int arr[], int panjang)
{
    int comparison, swapping, movement;

    comparison = 0;
    swapping = 0;
    movement = 0;
    
    printf("\nData setelah Shell Sort:\n");

    for (int gap = panjang / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < panjang; i++) {
            int temp = arr[i];
            int j;

            movement++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparison++;
                swapping++;
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }

    print_array(arr, panjang);
    printf("Jumlah pembandingan: %i\n", comparison);
    printf("Jumlah penukaran: %i\n", swapping);
    printf("Jumlah pergeseran: %i\n", movement);
}

void print_array(int arr[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
