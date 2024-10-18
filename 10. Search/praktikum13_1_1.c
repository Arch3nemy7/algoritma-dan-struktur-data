#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(int [], int);
int sequential_search(int [], int, int);
int binary_search(int [], int, int, int);
void shell_sort(int [], int);
void display_array(int [], int);
void generate_unique_data(int [], int);

int main()
{
    int size;
    int* arr;

    arr = (int*)malloc(size * sizeof(int));
    
    system("cls");

    printf("Masukkan jumlah data: ");
    scanf("%i", &size);
    fflush(stdin);

    generate_unique_data(arr, size);

    display_array(arr, size);
    menu(arr, size);

    free(arr);

    return 0;
}

void generate_unique_data(int arr[], int size)
{
    int *temp, randomIndex;

    temp = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        temp[i] = i;
    }

    srand(time(0));
    for (int i = 0; i < size; i++) {
        randomIndex = rand() % (size - i) + i;
        arr[i] = temp[randomIndex];
        temp[randomIndex] = temp[i];
    }

    free(temp);
}

void menu(int arr[], int size)
{
    int choice, key, index, *sortedArr;
    clock_t start, stop;
    double time_taken;

    sortedArr = (int*)malloc(size * sizeof(int));
    memcpy(sortedArr, arr, size * sizeof(int));

    while (1) {
        printf("\nMenu Searching\n");
        printf("1. Sequential Search pada unsorted array\n");
        printf("2. Sequential Search pada sorted array\n");
        printf("3. Binary Search pada sorted array\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%i", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("Masukkan angka yang ingin dicari: ");
                scanf("%i", &key);
                fflush(stdin);

                start = clock();
                index = sequential_search(arr, size, key);
                stop = clock();
                time_taken = ((double)(stop - start) / CLOCKS_PER_SEC) * 1000000;

                if (index != -1) {
                    printf("Angka ditemukan pada index: %i\n", index);
                }
                else {
                    printf("Angka tidak ditemukan.\n");
                }

                printf("Waktu komputasi: %.2f\n", time_taken);
                break;
            case 2:
                shell_sort(sortedArr, size);
                printf("Masukkan angka yang ingin dicari: ");
                scanf("%i", &key);
                fflush(stdin);

                start = clock();
                index = sequential_search(sortedArr, size, key);
                stop = clock();
                time_taken = ((double)(stop - start) / CLOCKS_PER_SEC) * 1000000;

                if (index != -1) {
                    printf("Angka ditemukan pada index: %i\n", index);
                }
                else {
                    printf("Angka tidak ditemukan.\n");
                }

                printf("Waktu komputasi: %.2f\n", time_taken);
                memcpy(sortedArr, arr, size * sizeof(int));
                break;
            case 3:
                shell_sort(sortedArr, size);
                printf("Masukkan angka yang ingin dicari: ");
                scanf("%i", &key);
                fflush(stdin);

                start = clock();
                index = binary_search(sortedArr, 0, size - 1, key);
                stop = clock();
                time_taken = ((double)(stop - start) / CLOCKS_PER_SEC) * 1000000;

                if (index != -1) {
                    printf("\nAngka ditemukan pada index: %i\n", index);
                }
                else {
                    printf("\nAngka tidak ditemukan.\n");
                }

                printf("Waktu komputasi: %.2f\n", time_taken);
                memcpy(sortedArr, arr, size * sizeof(int));
                break;
            case 4:
                free(sortedArr);
                return;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

int sequential_search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int low, int high, int key)
{
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            return binary_search(arr, low, mid - 1, key);
        }
        else {
            return binary_search(arr, mid + 1, high, key);
        }
    }
    return -1;
}

void shell_sort(int arr[], int size)
{
    int temp, j;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            temp = arr[i];
            j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

void display_array(int arr[], int size)
{
    printf("Data yang di-generate:\n");
    for (int i = 0; i < size; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
