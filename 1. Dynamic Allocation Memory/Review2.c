#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 100

typedef struct {
    int hari, bulan, tahun;
} date;

typedef struct {
    int id;
    int gaji;
    char nama[MAKS], gender;
    date tgllahir;
} pegawai;

void input(pegawai *);
void hasil(pegawai *, int *);

int main()
{
    pegawai emp[MAKS];

    system("cls");

    input(emp);

    return 0;
}

void input(pegawai *employee)
{
    int i, j;

    puts("\t\tDATA PEGAWAI\n");

    printf("Berapa jumlah pegawai : ");
    scanf("%i", &j);
    fflush(stdin);

    for(i = 0; i < j; i++) {
        printf("\nData pegawai ke-%i\n", i + 1);
        employee[i].id = i + 1;

        printf("Nama\t\t\t: ");
        fgets(employee[i].nama, sizeof(employee[i].nama), stdin);
        employee[i].nama[strlen(employee[i].nama) - 1] = '\0';
        fflush(stdin);

        printf("Tgl lahir <dd-mm-yy>\t: ");
        scanf("%2i-%2i-%i", &employee[i].tgllahir.hari, &employee[i].tgllahir.bulan, &employee[i].tgllahir.tahun);
        fflush(stdin);

        printf("Jenis kelamin [L/P]\t: ");
        employee[i].gender = getchar();
        fflush(stdin);

        printf("Gaji/bln\t\t: ");
        scanf("%i", &employee[i].gaji);
        fflush(stdin);
    }

    system("cls");
    
    hasil(employee, &j);
}

void hasil(pegawai *pegaway, int *j)
{
    int i;

    puts("Data pegawai yang telah diinputkan");

    for(i = 0; i < *j; i++) {
        printf("\nNo id\t\t\t: %i\n", pegaway[i].id);
        printf("Nama\t\t\t: %s\n", pegaway[i].nama);
        printf("Tgl lahir\t\t: %2i-%2i-%i\n", pegaway[i].tgllahir.hari, pegaway[i].tgllahir.bulan, pegaway[i].tgllahir.tahun);
        printf("Jenis kelamin\t\t: %s\n", pegaway[i].gender == 'L' || pegaway[i].gender == 'l' ? "Laki-laki" : pegaway[i].gender == 'P' || pegaway[i].gender == 'p' ? "Perempuan" : "Non-binary");
        printf("Gaji/bln\t\t: Rp.%i.00\n", pegaway[i].gaji);
    }
}