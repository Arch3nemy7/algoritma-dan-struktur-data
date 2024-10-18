#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date dateOfBirth;
} student;

int isYounger(student, student);

int main()
{
    student student1, student2;

    // system("cls");

    // Input nama
    printf("Masukkan nama mahasiswa pertama : ");
    fgets(student1.name, sizeof(student1.name), stdin);
    student1.name[strlen(student1.name) - 1] = '\0';

    printf("Masukkan nama mahasiswa kedua : ");
    fgets(student2.name, sizeof(student2.name), stdin);
    student2.name[strlen(student2.name) - 1] = '\0';
    fflush(stdin);

    // Input tanggal
    printf("\nMasukkan tanggal lahir mahasiswa pertama (DD-MM-YYYY) : ");
    scanf("%i-%i-%i", &student1.dateOfBirth.day, &student1.dateOfBirth.month, &student1.dateOfBirth.year);

    printf("Masukkan tanggal lahir mahasiswa kedua (DD-MM-YYYY) : ");
    scanf("%i-%i-%i", &student2.dateOfBirth.day, &student2.dateOfBirth.month, &student2.dateOfBirth.year);

    if(isYounger(student1, student2) == 0){
        printf("%s is older than %s\n", student1.name, student2.name);
    }else if(isYounger(student1, student2) == 1){
        printf("%s is younger than %s\n", student1.name, student2.name);
    }else{
        printf("%s is the same age as %s\n", student1.name, student2.name);
    }

    return 0;
}

int isYounger(student stud1, student stud2)
{
    int cek;

    if(stud1.dateOfBirth.year < stud2.dateOfBirth.year){
        cek = 0;
    }else if(stud1.dateOfBirth.year == stud2.dateOfBirth.year){
        if(stud1.dateOfBirth.month < stud2.dateOfBirth.month){
            cek = 0;
        }else if(stud1.dateOfBirth.month == stud2.dateOfBirth.month){
            if(stud1.dateOfBirth.day < stud2.dateOfBirth.day){
                cek = 0;
            }else if(stud1.dateOfBirth.day == stud2.dateOfBirth.day){
                cek == 2;
            }else{
                cek = 1;
            }
        }else{
            cek = 1;
        }
    }else{
        cek = 1;
    }

    return cek;
}
