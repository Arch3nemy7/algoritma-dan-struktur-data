#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Dnode;
struct simpul {
    int no;
    char nama[100];
    float nilai;
    Dnode *next;
    Dnode *prev;
};

Dnode *head = NULL, *p;

void menu();
void alokasi();
void insert();
void awal();
void akhir();
void after();
void before();
void delete();
void hapusAwal();
void hapusAkhir();
void hapus_ttt();
void bebaskan(Dnode *);
void tampil();

int main()
{
    system("cls");

    do {
        menu();
        tampil();
    } while (1);

    return 0;
}

void menu()
{
    int pil;

    puts("Menu Utama");
    puts("1. Insert");
    puts("2. Delete");
    puts("3. Keluar");

    printf("Masukkan pilihan Anda : ");
    scanf("%i", &pil);
    fflush(stdin);

    switch (pil) {
    case 1:
        insert();
        break;
    case 2:
        delete();
        break;
    case 3:
        puts("Selesai.");
        exit(0);
    default:
        puts("Pilihan tidak ada. Exiting");
        exit(0);
    }
}

void insert()
{
    int pil;

    puts("Menu Insert");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. After");
    puts("4. Before");

    printf("Masukkan pilihan Anda : ");
    scanf("%i", &pil);
    fflush(stdin);

    switch (pil) {
    case 1:
        alokasi();
        awal();
        break;
    case 2:
        alokasi();
        akhir();
        break;
    case 3:
        alokasi();
        after();
        break;
    case 4:
        alokasi();
        before();
        break;
    default:
        printf("Pilihan tidak ada. Exiting");
        exit(0);
    }
}

void delete()
{
    int pil;

    puts("Menu Delete");
    puts("1. Awal");
    puts("2. Akhir");
    puts("3. Tertentu");

    printf("Masukkan pilihan Anda : ");
    scanf("%i", &pil);
    fflush(stdin);

    switch (pil) {
    case 1:
        hapusAwal();
        break;
    case 2:
        hapusAkhir();
        break;
    case 3:
        hapus_ttt();
        break;
    default:
        printf("Pilihan tidak ada. Exiting");
        exit(0);
    }
}

void alokasi()
{
    int number;
    char name[100];
    float score;

    p = (Dnode *) malloc(sizeof(Dnode));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("No\t: ");
        scanf("%i", &number);
        fflush(stdin);
        p->no = number;
        

        printf("Nama\t: ");
        fgets(name, sizeof(name), stdin);
        name[strlen(name) - 1] = '\0';
        strcpy(p->nama, name);
        fflush(stdin);
        
        printf("Nilai\t: ");
        scanf("%f", &score);
        fflush(stdin);
        p->nilai = score;

        p->next = NULL;
        p->prev = NULL;
    }
}

void awal()
{
    if (head != NULL) {
        p->next = head;
        head->prev = p->next;
    }
    head = p;
}

void akhir()
{
    Dnode *tail;

    tail = head;

    if (head == NULL) {
        head = p;
    } else {
        while (tail->next != NULL) {
            tail = tail->next;
        }

        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void after()
{
    int key;
    char jawab;
    Dnode *tail;

    tail = head;

    if (head == NULL) {
        awal();
        return;
    } else {
        printf("Disisipkan setelah nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);

        while (tail->no != key){
            if (tail->next == NULL){
                printf("%i tidak ada di dalam DLL\n", key);
                exit(0);
            } else {
                tail = tail->next;
            }
        }

        if (tail->next != NULL) {
            p->next = tail->next;
            tail->next->prev = p;
        }

        p->prev = tail;
        tail->next = p;
    }
}

void before()
{
    int key;
    char jawab;
    Dnode *tail;

    tail = head;

    if (head == NULL) {
        awal();
        return;
    } else {
        printf("Disisipkan sebelum nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);

        if (head->no == key) {
            awal();
            return;
        } else {
            while (tail->no != key) {
                if (tail->next == NULL) {
                    printf("%i tidak ada di dalam DLL. Exiting", key);
                    exit(0);
                } else {
                    tail = tail->next;
                }
            }
        }
        p->next = tail;
        p->prev = tail->prev;

        tail->prev->next = p;
        tail->prev = p;
    }    
}

void hapusAwal()
{
    Dnode *hapus;

    hapus = head;

    if (head == NULL) {
        puts("Data kosong. Silakan input data terlebih dahulu.");
        return;
    } else {
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = hapus->next;
            head->prev = NULL;
        }
    }
    
    bebaskan(hapus);
}

void hapusAkhir()
{
    Dnode *hapus;

    hapus = head;

    if (head == NULL) {
        puts("Data kosong. Silakan input data terlebih dahulu.");
        return;
    } else {
        if (hapus->next == NULL) {
            bebaskan(hapus);
            head = NULL;
        } else {
            while (hapus->next != NULL) {
                hapus = hapus->next;
            }
            hapus->prev->next = NULL;
        }
    }

    bebaskan(hapus);
}

void hapus_ttt()
{
    Dnode *tail;
    int key;

    printf("Masukkan data yang mau dihapus : ");
    scanf("%i", &key);
    fflush(stdin);

    tail = head;

    if (tail->no == key) {
        hapusAwal();
    } else {
        while (tail->no != key) {
            if (tail->next == NULL) {
                printf("%i tidak ada di dalam DLL. Exiting", key);
                exit(0);
            } else {
                tail = tail->next;
            }
        }
        tail->prev->next = tail->next;
        
        if (tail->next != NULL) {
            tail->next->prev = tail->prev;
        }
        
        bebaskan(tail);
    }
}

void bebaskan(Dnode *x)
{
    free(x);
    x = NULL;
}

void tampil()
{
    Dnode *baca;

    baca = head;

    puts("\nData yang telah diinputkan :");
    puts("No\tNama\tNilai");

    while (baca != NULL) {
        printf("%i\t", baca->no);
        printf("%s\t", baca->nama);
        printf("%g\t\n", baca->nilai);

        baca = baca->next;
    }
}