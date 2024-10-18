#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count;
    int front;
    int rear;
} queue;

void menu(queue *);
void inisialisasi(queue *);
int isFull(queue *);
int isEmpty(queue *);
void enqueue(itemType, queue *);
itemType dequeue(queue *);
void display(queue *);

int main()
{
    queue antrian;
    char jawab;

    system("cls");

    puts("Implementasi Queue dengan Menggunakan Array");
    inisialisasi(&antrian);

    do {
        menu(&antrian);
    } while (1);
    
    return 0;
}

void menu(queue *q)
{
    itemType x;
    int pil;

    puts("\nMenu Queue");
    puts("1. Mengisi queue (ENQUEUE)");
    puts("2. Mengambil isi queue (DEQUEUE)");
    puts("3. Menampilkan isi queue");
    puts("4. Keluar");
    
    printf("Masukkan pilihan Anda: ");
    scanf("%i", &pil);
    fflush(stdin);

    switch (pil) {
        case 1:
            printf("Masukkan elemen yang akan disimpan: ");
            scanf("%c", &x);
            enqueue(x, q);
            break;
        case 2:
            printf("data yang diambil dari queue adalah %c\n", dequeue(q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            puts("Selesai.");
            exit(0);
        default:
            puts("Pilihan tidak ada. Exiting.");
            exit(0);
    }
}

void inisialisasi(queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int isFull(queue *q)
{
    if (q->count == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(queue *q)
{
    if (q->count == 0) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(itemType x, queue *q)
{
    if (isFull(q) == 1) {
        puts("Queue penuh, tidak bisa menyimpan data.");
    } else {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1) % MAX;
        q->count++;
    }
}

itemType dequeue(queue *q)
{
    itemType temp;

    if (isEmpty(q) == 1) {
        puts("Queue kosong, tidak bisa mengambil data.");
    } else {
        temp = q->data[q->front];
        q->front = (q->front + 1) % MAX;
        q->count--;
        
        return temp;
    }
}

void display(queue *q)
{
    if (isEmpty(q) == 1) {
        puts("Queue kosong!\n");
        return;
    } else {
        printf("Isi queue: \n");
        for (int i = 0; i < q->count; i++) {
            printf("%c\n", q->data[(q->front + i) % MAX]);
        }
    }
}