#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct {
    int no;
    char nama[50];
    char nilai;
} siswa;

void input_data(siswa [], int);
void menu();
int mode_urut();
void insertion_sort(siswa [], int, int);
void selection_sort(siswa [], int, int);
void print_data(siswa [], int);

int main()
{
    siswa data[MAX_SIZE];
    int jumlah_data;

    system("cls");
    
    printf("Masukkan jumlah data siswa (max 10): ");
    scanf("%i", &jumlah_data);
    fflush(stdin);

    input_data(data, jumlah_data);
    menu(data, jumlah_data);

    return 0;
}

void input_data(siswa data[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        printf("\nData siswa %i:\n", i + 1);
        printf("NO: ");
        scanf("%i", &data[i].no);
        fflush(stdin);
        printf("Nama: ");
        scanf("%s", data[i].nama);
        fflush(stdin);
        printf("Nilai: ");
        scanf(" %i", &data[i].nilai);
        fflush(stdin);
    }
}

void menu(siswa data[], int jumlah_data)
{
    int pilihan_sorting;

    do {
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Keluar\n");
        printf("Pilihan anda [1/2/3]: ");
        scanf("%i", &pilihan_sorting);
        fflush(stdin);

        switch (pilihan_sorting) {
            case 1:
                printf("\nData setelah pengurutan:\n");
                insertion_sort(data, jumlah_data, mode_urut());
                print_data(data, jumlah_data);
                break;

            case 2:
                printf("\nData setelah pengurutan:\n");
                selection_sort(data, jumlah_data, mode_urut());
                print_data(data, jumlah_data);
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

    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%i", &pilihan_order);
    fflush(stdin);

    return pilihan_order;
}

void insertion_sort(siswa data[], int panjang, int mode)
{
    for (int i = 1; i < panjang; i++) {
        siswa key;
        int j;

        key = data[i];
        j = i - 1;

        if (mode == 1) { 
            while (j >= 0 && data[j].no > key.no) {
                data[j + 1] = data[j];
                j--;
            }
        } else {
            while (j >= 0 && data[j].no < key.no) {
                data[j + 1] = data[j];
                j--;
            }
        }

        data[j + 1] = key;
    }
}

void selection_sort(siswa data[], int panjang, int mode)
{
    siswa temp;

    for (int i = 0; i < panjang - 1; i++) {
        int index_min = i;

        for (int j = i + 1; j < panjang; j++) {
            if (mode == 1 && data[j].no < data[index_min].no) {
                index_min = j;
            } else if (mode == 2 && data[j].no > data[index_min].no) {
                index_min = j;
            }
        }

        temp = data[index_min];
        data[index_min] = data[i];
        data[i] = temp;
    }
}

void print_data(siswa data[], int panjang)
{
    printf("\nNO\tNAMA\tNILAI\n");
    printf("--------------------\n");

    for (int i = 0; i < panjang; i++) {
        printf("%i\t%s\t%i\n", data[i].no, data[i].nama, data[i].nilai);
    }

    printf("--------------------\n");
}
