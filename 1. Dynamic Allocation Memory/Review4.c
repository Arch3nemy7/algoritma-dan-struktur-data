#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 9999

typedef struct {
    char nama[100];
    float tugas, uts, uas, nilaiAkhir;
} data;

typedef struct {
    char nama[100];
    float nilai;
} maks;

int banyak;

void input(data *);
void tampil(data *);

int main()
{
    data mhs[MAKS];
    int banyak;

    system("cls");

    input(mhs);
    tampil(mhs);

    return 0;
}

void input(data *datamhs)
{
    int i;

    printf("Berapa Jumlah mahasiswa ? ");
    scanf("%i", &banyak);
    fflush(stdin);

    for(i = 0; i < banyak; i++) {
        printf("\nMahasiswa ke-%i", i + 1);

        printf("\nNama\t\t : ");
        fgets(datamhs->nama, sizeof(datamhs->nama), stdin);
        datamhs->nama[strlen(datamhs->nama) - 1] = '\0';
        fflush(stdin);
        
        printf("Nilai Tugas\t : ");
        scanf("%f", &datamhs->tugas);
        fflush(stdin);
        
        printf("Nilai UTS\t : ");
        scanf("%f", &datamhs->uts);
        fflush(stdin);
        
        printf("Nilai UAS\t : ");
        scanf("%f", &datamhs->uas);
        fflush(stdin);
        datamhs++;
    }
}

void tampil(data *datamhs)
{
    int i = 0;
    float akhir = 0;
    maks max = {"", 0};

    puts("\t\t\tDAFTAR NILAI");
    puts("\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    puts("---------------------------------------------------------------------");
    puts("No\tNama\t\tNilai     Nilai     Nilai     Akhir     Grade");
    puts("\tMahasiswa\tTugas     UTS       UAS");
    puts("---------------------------------------------------------------------");

    for(i = 0; i < banyak; i++) {
        datamhs->nilaiAkhir = 0.2 * datamhs->tugas + 0.4 * datamhs->uts + 0.4 * datamhs->uas;
        
        if(max.nilai == 0 || datamhs->nilaiAkhir > max.nilai) {
            max.nilai = datamhs->nilaiAkhir;
            strcpy(max.nama, datamhs->nama);
        }
        printf("%i\t%s\t\t%g\t\t%g\t%g\t%g\t%c\n", i + 1, datamhs->nama, datamhs->tugas, datamhs->uts, datamhs->uas, datamhs->nilaiAkhir, datamhs->nilaiAkhir >= 80 ? 'A' : datamhs->nilaiAkhir >= 70 ? 'B' : datamhs->nilaiAkhir >= 60 ? 'C' : datamhs->nilaiAkhir >= 50 ? 'D' : 'E');
        datamhs++;
    }
    puts("---------------------------------------------------------------------");
    
    printf("\nTotal Mahasiswa = %i", banyak);
    puts("\nNilai tertinggi");
    printf("Nama\t\t= %s", max.nama);
    printf("\nNilai tertinggi\t= %g", max.nilai);
}