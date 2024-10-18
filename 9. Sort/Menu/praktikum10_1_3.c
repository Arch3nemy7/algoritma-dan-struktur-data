#include <stdio.h>
#include <stdlib.h>

void menu(int [], int);
int mode_urut();
void insertion_sort(int [], int, int);
void selection_sort(int [], int, int);
void print_array(int [], int);

int main()
{
    int array[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
    int jumlah_data = sizeof(array) / sizeof(array[0]);

    system("cls");
    menu(array, jumlah_data);

    return 0;
}

void menu(int array[], int jumlah_data)
{
    int pilihan_sorting;

    do {
        printf("MENU METODE SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Keluar\n");
        printf("Pilihan anda [1/2/3]: ");
        scanf("%i", &pilihan_sorting);
        fflush(stdin);

        switch (pilihan_sorting) {
            case 1:
                printf("\nSebelum pengurutan: ");
                print_array(array, jumlah_data);

                printf("Setelah pengurutan: ");
                insertion_sort(array, jumlah_data, mode_urut());
                print_array(array, jumlah_data);
                printf("\n");
                break;
            case 2:
                printf("\nSebelum pengurutan: ");
                print_array(array, jumlah_data);

                printf("Setelah pengurutan: ");
                selection_sort(array, jumlah_data, mode_urut());
                print_array(array, jumlah_data);
                printf("\n");
                break;
            case 3:
                puts("Selesai.");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n\n");
        }
    } while (pilihan_sorting != 3);
}

int mode_urut()
{
    int pilihan_order;
    
    printf("\nMENU METODE SORTING\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%i", &pilihan_order);
    fflush(stdin);

    return pilihan_order;
}

void insertion_sort(int arr[], int panjang, int mode)
{
    for (int i = 1; i < panjang; i++) {
        int key = arr[i];
        int j = i - 1;

        if (mode == 1) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int panjang, int mode)
{
    for (int i = 0; i < panjang - 1; i++) {
        int index_min = i;

        for (int j = i + 1; j < panjang; j++) {
            if (mode == 1 && arr[j] < arr[index_min]) {
                index_min = j;
            } else if (mode == 2 && arr[j] > arr[index_min]) {
                index_min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[index_min];
        arr[index_min] = temp;
    }
}

void print_array(int arr[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
}
