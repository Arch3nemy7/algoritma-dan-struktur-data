#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int [], int);
void selection_sort(int [], int, int);
void insertion_sort(int [], int, int);
void bubble_sort(int [], int, int);
void shell_sort(int [], int, int);
void merge(int [], int, int, int, int);
void merge_sort(int [], int, int, int);
void swap(int *, int *);
int partition(int [], int, int, int);
void quick_sort(int [], int, int, int);
void print_array(int [], int);
void menu(int [], int);
int mode_urut();

int main()
{
    int n = 30000, arr[n];
    
    generate_random_array(arr, n);
    printf("Data Awal:\n");
    print_array(arr, n);

    menu(arr, n);

    return 0;
}

void generate_random_array(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void menu(int arr[], int n)
{
    int pilihan_sorting;
    clock_t start, end;
    double time_taken;

    do {
        printf("\nMENU METODE SORTING\n");
        printf("1. Selection Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Quick Sort\n");
        printf("7. Keluar\n");
        printf("Pilih metode sorting [1/2/3/4/5/6/7]: ");
        scanf("%d", &pilihan_sorting);
        fflush(stdin);

        switch (pilihan_sorting) {
            case 1:
                printf("Selection Sort:\n");
                start = clock();
                selection_sort(arr, n, mode_urut());
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Sorted Array:\n");
                print_array(arr, n);
                printf("Time taken: %f seconds\n", time_taken);
                break;
            case 2:
                printf("Insertion Sort:\n");
                start = clock();
                insertion_sort(arr, n, mode_urut());
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Sorted Array:\n");
                print_array(arr, n);
                printf("Time taken: %f seconds\n", time_taken);
                break;
            case 3:
                printf("Bubble Sort:\n");
                start = clock();
                bubble_sort(arr, n, mode_urut());
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Sorted Array:\n");
                print_array(arr, n);
                printf("Time taken: %f seconds\n", time_taken);
                break;
            case 4:
                printf("Shell Sort:\n");
                start = clock();
                shell_sort(arr, n, mode_urut());
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Sorted Array:\n");
                print_array(arr, n);
                printf("Time taken: %f seconds\n", time_taken);
                break;
            case 5:
                printf("Merge Sort:\n");
                start = clock();
                merge_sort(arr, 0, n - 1, mode_urut());
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Sorted Array:\n");
                print_array(arr, n);
                printf("Time taken: %f seconds\n", time_taken);
                break;
            case 6:
                printf("Quick Sort:\n");
                start = clock();
                quick_sort(arr, 0, n - 1, mode_urut());
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Sorted Array:\n");
                print_array(arr, n);
                printf("Time taken: %f seconds\n", time_taken);
                break;
            case 7:
                puts("Selesai.");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                return;
        }    
    } while (pilihan_sorting != 7);
}

int mode_urut()
{
    int pilihan_mode;

    printf("\nPilih mode pengurutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilih mode [1/2]: ");
    scanf("%d", &pilihan_mode);
    fflush(stdin);

    return pilihan_mode;
}

void selection_sort(int arr[], int panjang, int mode)
{
    for (int i = 0; i < panjang - 1; i++) {
        int index_min;
        
        index_min = i;

        switch (mode) {
            case 1:
                for (int j = i + 1; j < panjang; j++) {
                    if (arr[j] < arr[index_min]) {
                        index_min = j;
                    }
                }
                break;
            case 2:
                for (int j = i + 1; j < panjang; j++) {
                    if (arr[j] > arr[index_min]) {
                        index_min = j;
                    }
                }
                break;
            default:
                printf("Mode tidak valid. Silakan pilih 1 untuk menaik atau 2 untuk menurun.\n");
                return;
        }

        swap(&arr[i], &arr[index_min]);
    }
}

void insertion_sort(int arr[], int panjang, int mode)
{
    for (int i = 1; i < panjang; i++) {
        int key;
        int j;
        
        key = arr[i];
        j = i - 1;

        switch (mode) {
            case 1:
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                break;
            case 2:
                while (j >= 0 && arr[j] < key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                break;
            default:
                printf("Mode tidak valid. Silakan pilih 1 untuk menaik atau 2 untuk menurun.\n");
                return;
        }

        arr[j + 1] = key;
    }
}


void bubble_sort(int arr[], int panjang, int mode)
{
    for (int i = 0; i < panjang - 1; i++) {
        for (int j = 0; j < panjang - i - 1; j++) {
            switch (mode) {
                case 1:
                    if (arr[j] > arr[j + 1]) {
                        swap(&arr[j], &arr[j + 1]);
                    }
                    break;
                case 2:
                    if (arr[j] < arr[j + 1]) {
                        swap(&arr[j], &arr[j + 1]);
                    }
                    break;
                default:
                    printf("Mode tidak valid. Silakan pilih 1 untuk menaik atau 2 untuk menurun.\n");
                    return;
            }
        }
    }
}

void shell_sort(int arr[], int n, int mode)
{
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp;
            int j;

            temp = arr[i];
            for (j = i; j >= gap && ((mode == 1 && arr[j - gap] > temp) || (mode == 2 && arr[j - gap] < temp)); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int l, int m, int r, int mode)
{
    int i, j, k, n1, n2;
    int L[n1], R[n2];

    n1 = m - l + 1;
    n2 = r - m;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        switch (mode) {
            case 1:
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                break;
            case 2:
                if (L[i] >= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                break;
            default:
                printf("Mode tidak valid. Silakan pilih 1 untuk menaik atau 2 untuk menurun.\n");
                return;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r, int mode)
{
    if (l < r) {
        int m;
        
        m = l + (r - l) / 2;

        merge_sort(arr, l, m, mode);
        merge_sort(arr, m + 1, r, mode);
        merge(arr, l, m, r, mode);
    }
}

void swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int mode)
{
    int pivot, i;
    
    pivot = arr[high];
    i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        switch (mode) {
            case 1:
                if (arr[j] <= pivot) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
                break;
            case 2:
                if (arr[j] >= pivot) {
                    i++;
                    swap(&arr[i], &arr[j]);
                }
                break;
            default:
                printf("Mode tidak valid. Silakan pilih 1 untuk menaik atau 2 untuk menurun.\n");
                return -1;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high, int mode)
{
    if (low < high) {
        int pi;
        
        pi = partition(arr, low, high, mode);

        quick_sort(arr, low, pi - 1, mode);
        quick_sort(arr, pi + 1, high, mode);
    }
}


void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
