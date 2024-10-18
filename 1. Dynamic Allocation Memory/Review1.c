#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 9999

struct data {
    char nama[100];
    float tugas, uts, uas;
};

int banyak;

void input(struct data []);
void tampil(struct data []);

int main()
{
    struct data mhs[MAKS];

    system("cls");

    input(mhs);
    tampil(mhs);

    return 0;
}

void input(struct data datamhs[])
{
    int i;

    printf("Berapa Jumlah mahasiswa ? ");
    scanf("%i", &banyak);
    fflush(stdin);

    for(i = 0; i < banyak; i++) {
        printf("\nMahasiswa ke-%i", i + 1);

        printf("\nNama\t\t : ");
        fgets(datamhs[i].nama, sizeof(datamhs[i].nama), stdin);
        datamhs[i].nama[strlen(datamhs[i].nama) - 1] = '\0';
        // fflush(stdin);
        
        printf("Nilai Tugas\t : ");
        scanf("%f", &datamhs[i].tugas);
        
        printf("Nilai UTS\t : ");
        scanf("%f", &datamhs[i].uts);
        
        printf("Nilai UAS\t : ");
        scanf("%f", &datamhs[i].uas);
        fflush(stdin);
    }

}

void tampil(struct data datamhs[])
{
    int i = 0;
    float akhir = 0;

    puts("\t\t\tDAFTAR NILAI");
    puts("\t\tMATAKULIAH KONSEP PEMROGRAMAN");
    puts("---------------------------------------------------------------------");
    puts("No\tNama\t\tNilai     Nilai     Nilai     Akhir     Grade");
    puts("\tMahasiswa\tTugas     UTS       UAS");
    puts("---------------------------------------------------------------------");

    for(i = 0; i < banyak; i++) {
        akhir = 0.2 * datamhs[i].tugas + 0.4 * datamhs[i].uts + 0.4 * datamhs[i].uas;
        printf("%i\t%s\t\t%g\t\t%g\t%g\t%g\t%c\n", i + 1, datamhs[i].nama, datamhs[i].tugas, datamhs[i].uts, datamhs[i].uas, akhir, akhir >= 80 ? 'A' : akhir >= 70 ? 'B' : akhir >= 60 ? 'C' : akhir >= 50 ? 'D' : 'E');
    }
    puts("---------------------------------------------------------------------");
}