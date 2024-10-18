#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct {
    int no;
    char nama[50];
    int nilai;
} siswa;

void input_data(siswa [], int);
void menu(siswa [], int);
int mode_urut();
int urut();
void insertion_sort(siswa [], int, int, int);
void selection_sort(siswa [], int, int, int);
void bubble_sort(siswa [], int, int, int);
void shell_sort(siswa [], int, int, int);
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

void menu(siswa data[], int jumlah_data)
{
    int pilihan_sorting, pilihan_urutan;

    do {
        printf("\nMENU METODE SORTING\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Shell Sort\n");
        printf("5. Keluar\n");
        printf("Pilihan anda [1/2/3/4/5]: ");
        scanf("%i", &pilihan_sorting);

        switch (pilihan_sorting) {
        case 1:
            insertion_sort(data, jumlah_data, mode_urut(), urut());
            printf("\nData setelah diurutkan:\n");
            print_data(data, jumlah_data);
            break;
        case 2:
            selection_sort(data, jumlah_data, mode_urut(), urut());
            printf("\nData setelah diurutkan:\n");
            print_data(data, jumlah_data);
            break;
        case 3:
            bubble_sort(data, jumlah_data, mode_urut(), urut());
            printf("\nData setelah diurutkan:\n");
            print_data(data, jumlah_data);
            break;
        case 4:
            shell_sort(data, jumlah_data, mode_urut(), urut());
            printf("\nData setelah diurutkan:\n");
            print_data(data, jumlah_data);
            break;
        case 5:
            puts("Selesai.");
            break;
        default:
            printf("Pilihan tidak valid!\n");
            break;
        }
    } while (pilihan_sorting != 5);
}

void input_data(siswa data[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        printf("Data Mahasiswa ke-%i\n", i + 1);
        printf("NO: ");
        scanf("%i", &data[i].no);
        printf("Nama: ");
        scanf("%s", data[i].nama);
        printf("Nilai: ");
        scanf("%i", &data[i].nilai);
        printf("\n");
    }
}

int mode_urut()
{
    int pilihan_order;

    printf("\nPengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Pilihan anda [1/2]: ");
    scanf("%i", &pilihan_order);

    return pilihan_order;
}

int urut()
{
    int pilihan_urutan;

    printf("\nPengurutan berdasarkan:\n");
    printf("1. No\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%i", &pilihan_urutan);

    return pilihan_urutan;
}

void insertion_sort(siswa data[], int panjang, int mode, int urutan)
{
    for (int i = 1; i < panjang; i++) {
        siswa key;
        int j;
        
        key = data[i];
        j = i - 1;

        switch (mode) {
            case 1:
                switch (urutan) {
                    case 1:
                        while (j >= 0 && data[j].no > key.no) {
                            data[j + 1] = data[j];
                            j--;
                        }
                        break;
                    case 2:
                        while (j >= 0 && strcmp(data[j].nama, key.nama) > 0) {
                            data[j + 1] = data[j];
                            j--;
                        }
                        break;
                    case 3:
                        while (j >= 0 && data[j].nilai > key.nilai) {
                            data[j + 1] = data[j];
                            j--;
                        }
                        break;
                }
                break;
            case 2:
                switch (urutan) {
                    case 1:
                        while (j >= 0 && data[j].no < key.no) {
                            data[j + 1] = data[j];
                            j--;
                        }
                        break;
                    case 2:
                        while (j >= 0 && strcmp(data[j].nama, key.nama) < 0) {
                            data[j + 1] = data[j];
                            j--;
                        }
                        break;
                    case 3:
                        while (j >= 0 && data[j].nilai < key.nilai) {
                            data[j + 1] = data[j];
                            j--;
                        }
                        break;
                }
                break;
        }
        data[j + 1] = key;
    }
}

void selection_sort(siswa data[], int panjang, int mode, int urutan)
{
    siswa temp;

    for (int i = 0; i < panjang - 1; i++) {
        int index_min = i;

        for (int j = i + 1; j < panjang; j++) {
            switch (mode) {
                case 1:
                    switch (urutan) {
                        case 1:
                            if (data[j].no < data[index_min].no) {
                                index_min = j;
                            }
                            break;
                        case 2:
                            if (strcmp(data[j].nama, data[index_min].nama) < 0) {
                                index_min = j;
                            }
                            break;
                        case 3:
                            if (data[j].nilai < data[index_min].nilai) {
                                index_min = j;
                            }
                            break;
                    }
                    break;
                case 2:
                    switch (urutan) {
                        case 1:
                            if (data[j].no > data[index_min].no) {
                                index_min = j;
                            }
                            break;
                        case 2:
                            if (strcmp(data[j].nama, data[index_min].nama) > 0) {
                                index_min = j;
                            }
                            break;
                        case 3:
                            if (data[j].nilai > data[index_min].nilai) {
                                index_min = j;
                            }
                            break;
                    }
                    break;
            }
        }

        temp = data[index_min];
        data[index_min] = data[i];
        data[i] = temp;
    }
}

void bubble_sort(siswa data[], int panjang, int mode, int urutan)
{
    siswa temp;

    for (int  i = 0; i < panjang - 1; i++) {
        for (int j = 0; j < panjang - i - 1; j++) {
            switch (mode) {
                case 1:
                    switch (urutan) {
                        case 1:
                            if (data[j].no > data[j + 1].no) {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                            break;
                        case 2:
                            if (strcmp(data[j].nama, data[j + 1].nama) > 0) {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                            break;
                        case 3:
                            if (data[j].nilai > data[j + 1].nilai) {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                            break;
                    }
                    break;
                case 2:
                    switch (urutan) {
                        case 1:
                            if (data[j].no < data[j + 1].no) {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                            break;
                        case 2:
                            if (strcmp(data[j].nama, data[j + 1].nama) < 0) {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                            break;
                        case 3:
                            if (data[j].nilai < data[j + 1].nilai) {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                            break;
                    }
                    break;
            }
        }
    }
}

void shell_sort(siswa data[], int panjang, int mode, int urutan)
{
    int gap, i, j;
    siswa temp;

    for (gap = panjang / 2; gap > 0; gap /= 2) {
        for (i = gap; i < panjang; i++) {
            temp = data[i];

            for (j = i; j >= gap; j -= gap) {
                switch (mode) {
                    case 1:
                        switch (urutan) {
                            case 1:
                                if (data[j - gap].no > temp.no) {
                                    data[j] = data[j - gap];
                                } else {
                                    break;
                                }
                                break;
                            case 2:
                                if (strcmp(data[j - gap].nama, temp.nama) > 0) {
                                    data[j] = data[j - gap];
                                } else {
                                    break;
                                }
                                break;
                            case 3:
                                if (data[j - gap].nilai > temp.nilai) {
                                    data[j] = data[j - gap];
                                } else {
                                    break;
                                }
                                break;
                        }
                        break;
                    case 2:
                        switch (urutan) {
                            case 1:
                                if (data[j - gap].no < temp.no) {
                                    data[j] = data[j - gap];
                                } else {
                                    break;
                                }
                                break;
                            case 2:
                                if (strcmp(data[j - gap].nama, temp.nama) < 0) {
                                    data[j] = data[j - gap];
                                } else {
                                    break;
                                }
                                break;
                            case 3:
                                if (data[j - gap].nilai < temp.nilai) {
                                    data[j] = data[j - gap];
                                } else {
                                    break;
                                }
                                break;
                        }
                        break;
                }
            }

            data[j] = temp;
        }
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
