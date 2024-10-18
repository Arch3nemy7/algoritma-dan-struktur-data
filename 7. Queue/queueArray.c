#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef char itemType;
typedef struct {
    itemType data[MAX];
    int count, front, rear;
} queue;

void inisialisasi(queue *);
int isFull(queue *);
int isEmpty(queue *);
void enqueue(itemType, queue *);
itemType dequeue(queue *);

int main()
{
    queue antrian;
    char jawab;
    itemType x;

    system("cls");

    puts("Implementasi Queue dengan Menggunakan Array");
    inisialisasi(&antrian);
    puts("Mengisi Queue");

    do {
        printf("Masukkan elemen yang akan disimpan: ");
        scanf("%c", &x);
        fflush(stdin);
        enqueue(x, &antrian);
        printf("Ada data lagi? ");
        jawab = getchar();
        fflush(stdin);
    } while (jawab == 'Y' || jawab == 'y');

    puts("");

    while (isEmpty(&antrian) == 0)  {
        printf("%c\n", dequeue(&antrian));
    }
    
    return 0;
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