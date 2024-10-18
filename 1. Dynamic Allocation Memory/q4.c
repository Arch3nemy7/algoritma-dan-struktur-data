#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hari, bulan, tahun;
} tanggal;

typedef struct {
    tanggal tanggal;
} Date;

int sameday(Date, Date);

int main()
{
    Date datedate1, datedate2;

    system("cls");
    
    printf("Masukkan tanggal pertama (DD-MM-YYYY) : ");
    scanf("%i-%i-%i", &datedate1.tanggal.hari, &datedate1.tanggal.bulan, &datedate1.tanggal.tahun);

    printf("Masukkan tanggal kedua (DD-MM-YYYY): ");
    scanf("%i-%i-%i", &datedate2.tanggal.hari, &datedate2.tanggal.bulan, &datedate2.tanggal.tahun);

    if(sameday(datedate1, datedate2) == 1){
        printf("It is the same day\n");
    }else{
        printf("It is not the same day\n");
    }
    
    return 0;
}

int sameday(Date tgl1, Date tgl2)
{
    if(tgl1.tanggal.hari == tgl2.tanggal.hari && tgl1.tanggal.bulan == tgl2.tanggal.bulan && tgl1.tanggal.tahun == tgl2.tanggal.tahun){
        return 1;
    }else{
        return 0;
    }
}