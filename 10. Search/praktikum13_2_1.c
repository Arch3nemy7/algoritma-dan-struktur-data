#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int no;
    char nama[100];
    int nilai;
} mhs;

void input_data(mhs [], int);
void menu(mhs [], int);
void sequentialSearch(mhs [], int, int);
void binarySearch(mhs [], int, int);
void shellSort(mhs [], int);
void print_data(mhs [], int, int);

int main()
{
    int size;
    mhs *data;

    data = (mhs*)malloc(size * sizeof(mhs));

    system("cls");

    printf("Masukkan jumlah data: ");
    scanf("%i", &size);
    fflush(stdin);

    input_data(data, size);
    menu(data, size);

    free(data);

    return 0;
}

void input_data(mhs data[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("\nData ke-%d\n", i + 1);
        printf("NO: ");
        scanf("%d", &data[i].no);
        fflush(stdin);

        printf("Nama: ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strcspn(data[i].nama, "\n")] = 0;

        printf("Nilai: ");
        scanf("%d", &data[i].nilai);
        fflush(stdin);
    }
}

void menu(mhs data[], int size)
{
    int choice, bentukData, searchBy;

    while (1) {
        printf("\nMENU METODE SEARCHING\n");
        printf("1. Tampilkan Data\n");
        printf("2. Sequential Search\n");
        printf("3. Binary Search\n");
        printf("4. Keluar\n");
        printf("Pilihan anda [1/2/3/4]: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("\nBENTUK DATA\n");
                printf("1. Tidak Terurut\n");
                printf("2. Terurut Berdasarkan No\n");
                printf("Pilihan anda [1/2]: ");
                scanf("%d", &bentukData);
                fflush(stdin);

                print_data(data, size, bentukData);
                break;
            case 2:
                printf("\nPENCARIAN BERDASARKAN\n");
                printf("1. No\n");
                printf("2. Nama\n");
                printf("Pilihan anda [1/2]: ");
                scanf("%d", &searchBy);
                fflush(stdin);

                sequentialSearch(data, size, searchBy);
                break;
            case 3:
                printf("\nPENCARIAN BERDASARKAN\n");
                printf("1. No\n");
                printf("2. Nama\n");
                printf("Pilihan anda [1/2]: ");
                scanf("%d", &searchBy);
                fflush(stdin);

                binarySearch(data, size, searchBy);
                break;
            case 4:
                return;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

void sequentialSearch(mhs data[], int size, int searchBy)
{
    int keyNo, found = 0;
    char keyNama[100];
    int count = 0;

    if (searchBy == 1) {
        printf("Masukkan No yang ingin dicari: ");
        scanf("%d", &keyNo);

        for (int i = 0; i < size; i++) {
            if (data[i].no == keyNo) {
                found = 1;
                printf("\nData ditemukan pada indeks ke-%d\n", i);
                printf("NO: %d\n", data[i].no);
                printf("Nama: %s\n", data[i].nama);
                printf("Nilai: %d\n", data[i].nilai);
                count++;
            }
        }
    } else if (searchBy == 2) {
        printf("Masukkan Nama yang ingin dicari: ");
        fgets(keyNama, sizeof(keyNama), stdin);
        keyNama[strcspn(keyNama, "\n")] = 0;

        for (int i = 0; i < size; i++) {
            if (strcmp(data[i].nama, keyNama) == 0) {
                found = 1;
                printf("\nData ditemukan pada indeks ke-%d\n", i);
                printf("NO: %d\n", data[i].no);
                printf("Nama: %s\n", data[i].nama);
                printf("Nilai: %d\n", data[i].nilai);
                count++;
            }
        }
    } else {
        printf("\nPilihan tidak valid!\n");
        return;
    }

    if (!found) {
        printf("Data tidak ditemukan\n");
    } else {
        printf("Total data yang ditemukan: %d\n", count);
    }
}

void binarySearch(mhs data[], int size, int searchBy)
{
    int keyNo, found = 0;
    char keyNama[100];
    int count = 0;

    if (searchBy == 1) {
        printf("Masukkan No yang ingin dicari: ");
        scanf("%d", &keyNo);

        int low = 0, high = size - 1, mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (data[mid].no == keyNo) {
                found = 1;
                printf("\nData ditemukan pada indeks ke-%d\n", mid);
                printf("NO: %d\n", data[mid].no);
                printf("Nama: %s\n", data[mid].nama);
                printf("Nilai: %d\n", data[mid].nilai);
                count++;
                break;
            } else if (data[mid].no < keyNo) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    } else if (searchBy == 2) {
        printf("Masukkan Nama yang ingin dicari: ");
        fgets(keyNama, sizeof(keyNama), stdin);
        keyNama[strcspn(keyNama, "\n")] = 0;

        shellSort(data, size);

        int low = 0, high = size - 1, mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (strcmp(data[mid].nama, keyNama) == 0) {
                found = 1;
                printf("\nData ditemukan pada indeks ke-%d\n", mid);
                printf("NO: %d\n", data[mid].no);
                printf("Nama: %s\n", data[mid].nama);
                printf("Nilai: %d\n", data[mid].nilai);
                count++;
                break;
            } else if (strcmp(data[mid].nama, keyNama) < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    } else {
        printf("\nPilihan tidak valid!\n");
        return;
    }

    if (!found) {
        printf("Data tidak ditemukan\n");
    } else {
        printf("Total data yang ditemukan: %d\n", count);
    }
}

void shellSort(mhs data[], int size)
{
    int i, j, k;
    mhs temp;

    for (k = size / 2; k > 0; k /= 2) {
        for (i = k; i < size; i++) {
            temp = data[i];
            j = i;

            while (j >= k && strcmp(data[j - k].nama, temp.nama) > 0) {
                data[j] = data[j - k];
                j -= k;
            }

            data[j] = temp;
        }
    }
}

void print_data(mhs data[], int size, int bentukData)
{
    printf("\nDATA MAHASISWA\n");

    if (bentukData == 1) {
        for (int i = 0; i < size; i++) {
            printf("\nData ke-%d\n", i + 1);
            printf("NO: %d\n", data[i].no);
            printf("Nama: %s\n", data[i].nama);
            printf("Nilai: %d\n", data[i].nilai);
        }
    } else if (bentukData == 2) {
        for (int i = 0; i < size; i++) {
            printf("\nData ke-%d\n", i + 1);
            printf("NO: %d\n", data[i].no);
            printf("Nama: %s\n", data[i].nama);
            printf("Nilai: %d\n", data[i].nilai);
        }
    } else {
        printf("Pilihan tidak valid!\n");
    }
}
