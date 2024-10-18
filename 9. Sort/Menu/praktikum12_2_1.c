#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 10

typedef struct {
    int no;
    char nama[50];
    int nilai;
} siswa;

void input_data(siswa [], int);
void menu(siswa [], int);
int mode_sort();
int urut();
void selection_sort(siswa [], int, int, int);
void insertion_sort(siswa [], int, int, int);
void bubble_sort(siswa [], int, int, int);
void shell_sort(siswa [], int, int, int);
void merge(siswa [], int, int, int, int, int);
void merge_sort(siswa [], int, int, int, int);
void swap(siswa *, siswa *);
int partition(siswa [], int, int, int, int);
void quick_sort(siswa [], int, int, int, int);
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

void menu(siswa data[], int n)
{
    int pilihan_sorting;

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
                selection_sort(data, n, mode_sort(), urut());
                printf("Data Terurut:\n");
                print_data(data, n);
                break;
            case 2:
                printf("Insertion Sort:\n");
                insertion_sort(data, n, mode_sort(), urut());
                printf("Data Terurut:\n");
                print_data(data, n);
                break;
            case 3:
                printf("Bubble Sort:\n");
                bubble_sort(data, n, mode_sort(), urut());
                printf("Data Terurut:\n");
                print_data(data, n);
                break;
            case 4:
                printf("Shell Sort:\n");
                shell_sort(data, n, mode_sort(), urut());
                printf("Data Terurut:\n");
                print_data(data, n);
                break;
            case 5:
                printf("Merge Sort:\n");
                merge_sort(data, 0, n - 1, mode_sort(), urut());
                printf("Data Terurut:\n");
                print_data(data, n);
                break;
            case 6:
                printf("Quick Sort:\n");
                quick_sort(data, 0, n - 1, mode_sort(), urut());
                printf("Data Terurut:\n");
                print_data(data, n);
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

void input_data(siswa data[], int panjang)
{
    for (int i = 0; i < panjang; i++) {
        printf("Data Mahasiswa ke-%i\n", i + 1);
        printf("NO: ");
        scanf("%i", &data[i].no);
        fflush(stdin);
        printf("Nama: ");
        scanf("%s", data[i].nama);
        fflush(stdin);
        printf("Nilai: ");
        scanf("%i", &data[i].nilai);
        fflush(stdin);
        printf("\n");
    }
}

int mode_sort()
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

int urut()
{
    int pilihan_urutan;

    printf("\nPengurutan berdasarkan:\n");
    printf("1. No\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan anda [1/2/3]: ");
    scanf("%i", &pilihan_urutan);
    fflush(stdin);

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
    for (int i = 0; i < panjang - 1; i++) {
        for (int j = 0; j < panjang - i - 1; j++) {
            switch (mode) {
                case 1:
                    switch (urutan) {
                        case 1:
                            if (data[j].no > data[j + 1].no) {
                                swap(&data[j], &data[j + 1]);
                            }
                            break;
                        case 2:
                            if (strcmp(data[j].nama, data[j + 1].nama) > 0) {
                                swap(&data[j], &data[j + 1]);
                            }
                            break;
                        case 3:
                            if (data[j].nilai > data[j + 1].nilai) {
                                swap(&data[j], &data[j + 1]);
                            }
                            break;
                    }
                    break;
                case 2:
                    switch (urutan) {
                        case 1:
                            if (data[j].no < data[j + 1].no) {
                                swap(&data[j], &data[j + 1]);
                            }
                            break;
                        case 2:
                            if (strcmp(data[j].nama, data[j + 1].nama) < 0) {
                                swap(&data[j], &data[j + 1]);
                            }
                            break;
                        case 3:
                            if (data[j].nilai < data[j + 1].nilai) {
                                swap(&data[j], &data[j + 1]);
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
    int gap;
    
    gap = panjang / 2;

    while (gap > 0) {
        for (int i = gap; i < panjang; i++) {
            siswa temp;
            int j;
            
            temp = data[i];
            j = i;

            switch (mode) {
                case 1:
                    switch (urutan) {
                        case 1:
                            while (j >= gap && data[j - gap].no > temp.no) {
                                data[j] = data[j - gap];
                                j -= gap;
                            }
                            break;
                        case 2:
                            while (j >= gap && strcmp(data[j - gap].nama, temp.nama) > 0) {
                                data[j] = data[j - gap];
                                j -= gap;
                            }
                            break;
                        case 3:
                            while (j >= gap && data[j - gap].nilai > temp.nilai) {
                                data[j] = data[j - gap];
                                j -= gap;
                            }
                            break;
                    }
                    break;
                case 2:
                    switch (urutan) {
                        case 1:
                            while (j >= gap && data[j - gap].no < temp.no) {
                                data[j] = data[j - gap];
                                j -= gap;
                            }
                            break;
                        case 2:
                            while (j >= gap && strcmp(data[j - gap].nama, temp.nama) < 0) {
                                data[j] = data[j - gap];
                                j -= gap;
                            }
                            break;
                        case 3:
                            while (j >= gap && data[j - gap].nilai < temp.nilai) {
                                data[j] = data[j - gap];
                                j -= gap;
                            }
                            break;
                    }
                    break;
            }

            data[j] = temp;
        }

        gap /= 2;
    }
}


void merge(siswa data[], int low, int mid, int high, int mode, int urutan)
{
    int left_size, right_size;
    
    left_size = mid - low + 1;
    right_size = high - mid;

    siswa left[left_size];
    siswa right[right_size];

    for (int i = 0; i < left_size; i++) {
        left[i] = data[low + i];
    }

    for (int j = 0; j < right_size; j++) {
        right[j] = data[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    switch (mode) {
        case 1:
            switch (urutan) {
                case 1:
                    while (i < left_size && j < right_size) {
                        if (left[i].no <= right[j].no) {
                            data[k] = left[i];
                            i++;
                        } else {
                            data[k] = right[j];
                            j++;
                        }
                        k++;
                    }
                    break;
                case 2:
                    while (i < left_size && j < right_size) {
                        if (strcmp(left[i].nama, right[j].nama) <= 0) {
                            data[k] = left[i];
                            i++;
                        } else {
                            data[k] = right[j];
                            j++;
                        }
                        k++;
                    }
                    break;
                case 3:
                    while (i < left_size && j < right_size) {
                        if (left[i].nilai <= right[j].nilai) {
                            data[k] = left[i];
                            i++;
                        } else {
                            data[k] = right[j];
                            j++;
                        }
                        k++;
                    }
                    break;
            }
            break;
        case 2:
            switch (urutan) {
                case 1:
                    while (i < left_size && j < right_size) {
                        if (left[i].no >= right[j].no) {
                            data[k] = left[i];
                            i++;
                        } else {
                            data[k] = right[j];
                            j++;
                        }
                        k++;
                    }
                    break;
                case 2:
                    while (i < left_size && j < right_size) {
                        if (strcmp(left[i].nama, right[j].nama) >= 0) {
                            data[k] = left[i];
                            i++;
                        } else {
                            data[k] = right[j];
                            j++;
                        }
                        k++;
                    }
                    break;
                case 3:
                    while (i < left_size && j < right_size) {
                        if (left[i].nilai >= right[j].nilai) {
                            data[k] = left[i];
                            i++;
                        } else {
                            data[k] = right[j];
                            j++;
                        }
                        k++;
                    }
                    break;
            }
            break;
    }

    while (i < left_size) {
        data[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        data[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(siswa data[], int low, int high, int mode, int urutan)
{
    if (low < high) {
        int mid;
        
        mid = low + (high - low) / 2;

        merge_sort(data, low, mid, mode, urutan);
        merge_sort(data, mid + 1, high, mode, urutan);

        merge(data, low, mid, high, mode, urutan);
    }
}

void swap(siswa *a, siswa *b)
{
    siswa temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(siswa data[], int low, int high, int mode, int urutan)
{
    siswa pivot;
    int i;
    
    pivot = data[high];
    i = low - 1;

    switch (mode) {
        case 1:
            switch (urutan) {
                case 1:
                    for (int j = low; j <= high - 1; j++) {
                        if (data[j].no <= pivot.no) {
                            i++;
                            swap(&data[i], &data[j]);
                        }
                    }
                    break;
                case 2:
                    for (int j = low; j <= high - 1; j++) {
                        if (strcmp(data[j].nama, pivot.nama) <= 0) {
                            i++;
                            swap(&data[i], &data[j]);
                        }
                    }
                    break;
                case 3:
                    for (int j = low; j <= high - 1; j++) {
                        if (data[j].nilai <= pivot.nilai) {
                            i++;
                            swap(&data[i], &data[j]);
                        }
                    }
                    break;
            }
            break;
        case 2:
            switch (urutan) {
                case 1:
                    for (int j = low; j <= high - 1; j++) {
                        if (data[j].no >= pivot.no) {
                            i++;
                            swap(&data[i], &data[j]);
                        }
                    }
                    break;
                case 2:
                    for (int j = low; j <= high - 1; j++) {
                        if (strcmp(data[j].nama, pivot.nama) >= 0) {
                            i++;
                            swap(&data[i], &data[j]);
                        }
                    }
                    break;
                case 3:
                    for (int j = low; j <= high - 1; j++) {
                        if (data[j].nilai >= pivot.nilai) {
                            i++;
                            swap(&data[i], &data[j]);
                        }
                    }
                    break;
            }
            break;
    }

    swap(&data[i + 1], &data[high]);

    return i + 1;
}

void quick_sort(siswa data[], int low, int high, int mode, int urutan)
{
    if (low < high) {
        int pi;
        
        pi = partition(data, low, high, mode, urutan);

        quick_sort(data, low, pi - 1, mode, urutan);
        quick_sort(data, pi + 1, high, mode, urutan);
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
