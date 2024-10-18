#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct simpul Node;
struct simpul {
    int data;
    Node *next;
};
Node *head = NULL, *tail, *p;

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
void bebaskan(Node *);
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
    int nilai;

    p = (Node *) malloc(sizeof(Node));

    if (p == NULL) {
        puts("Alokasi memori gagal. Exiting");
        exit(0);
    } else {
        printf("Data yang mau dimasukkan : ");
        scanf("%i", &nilai);
        fflush(stdin);
        
        p->data = nilai;        
        p->next = NULL;
    }
        
}

void awal()
{
    if (head != NULL) {
        p->next = head;
    }
    
    head = p;
}

void akhir()
{
    if (head == NULL) {
        head = p;
    } else {
        tail = head;
        
        while (tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = p;
        tail = tail->next;
    }
}

void after()
{
    int key;

    tail = head;
        
    if (head == NULL) {
        awal();
        return;
    } else {
        printf("Disisipkan setelah nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);
        
        while (tail->data != key){
            if (tail->next == NULL){
                printf("%i tidak ada di dalam SLL\n", key);
                exit(0);
            } else {
                tail = tail->next;
            }
        }
    }

    p->next = tail->next;
    tail->next = p;
}

void before()
{
    int key;
    Node *pbef, *bef;

    bef = head;

    if (head == NULL) {
        awal();
        return;
    } else {
        printf("Disisipkan sebelum nomor berapa ? ");
        scanf("%i", &key);
        fflush(stdin);

        if (head->data == key) {
            awal();
            return;
        } else {
            while (bef->data != key){
                if (bef->next == NULL){
                    printf("%i tidak ada di dalam SLL\n", key);
                    exit(0);
                } else {
                    pbef = bef;
                    bef = bef->next;
                }
            }
        }
    }

    p->next = bef;
    pbef->next = p;
}

void hapusAwal()
{
    Node *hapus;

    hapus = head;

    if (head == NULL) {
        puts("Data kosong. Silakan input data terlebih dahulu.");
        return;
    } else {
        if (hapus->next == NULL) {
            head = NULL;
        } else {
            head = hapus->next;
            bebaskan(hapus);
        }
    }
}

void hapusAkhir()
{
    Node *hapus, *phapus;

    hapus = head;

    if (head == NULL) {
        puts("Data kosong. Silakan input data terlebih dahulu.");
        return;
    } else {
        if (hapus->next == NULL) {
            head = NULL;
        } else {
            while (hapus->next != NULL) {
                phapus = hapus;
                hapus = hapus->next;
            }
            phapus->next = NULL;
        }
        
        bebaskan(hapus);
    }
}

void hapus_ttt()
{
    Node *hapus, *phapus;
    int key;

    if (head == NULL) {
        puts("Data kosong. Silakan input data terlebih dahulu.");
        return;
    } else {
        printf("Masukkan data yang mau dihapus : ");
        scanf("%i", &key);
        fflush(stdin);

        hapus = head;

        if (hapus->data == key) {
            hapusAwal();
        } else {
            while (hapus->data != key) {
                if (hapus->next == NULL) {
                    printf("%i Tidak ada di dalam SLL. Exiting", key);
                    exit(0);
                } else {
                    phapus = hapus;
                    hapus = hapus->next;
                }
            }
            phapus->next = hapus->next;
            bebaskan(hapus);
        }
    }
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}

void tampil()
{
    Node *baca;
    
    baca = head;

    printf("\nData yang ada dalam SLL\n");
    
    while (baca != NULL) {
        printf("%i\n", baca->data);
        baca = baca->next;
    }
}