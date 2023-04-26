#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char nama[20];
    char kelas[20];
    int kursi;
    float harga;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

void enqueue(struct queue *q) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("\nMasukkan Nama Penumpang: ");
    scanf("%s", temp->nama);
    printf("Pilih Jenis Kelas (Eksekutif/Ekonomi): ");
    scanf("%s", temp->kelas);
    printf("Masukkan No. Kursi: ");
    scanf("%d", &temp->kursi);
    printf("Masukkan Harga Tiket: ");
    scanf("%f", &temp->harga);
    temp->next = NULL;

    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct queue *q) {
    if(q->front == NULL) {
        printf("\nQueue is empty!");
        return;
    }
    printf("\n%s nama berikut telah dihilangkan dari data penumpang.", q->front->nama);
    struct node *temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;
    free(temp);
}

void display(struct queue *q) {
    if(q->front == NULL) {
        printf("\nData masih kosong! Silahkan membuat data penumpang terlebih dahulu.");
        return;
    }
    printf("\nData Penumpang: \n");
    struct node *temp = q->front;
    while(temp != NULL) {
        printf("\nNama Penumpang: %s\nTipe Kelas: %s\nNo. Kursi: %d\nHarga: %0.3f\n", temp->nama, temp->kelas, temp->kursi, temp->harga);
        temp = temp->next;
    }
}

int menu()
{
    printf("===============================================Selamat datang di program pemesanan tiket kereta===============================================\nSilahkan memilih pada laman menu!\n");
}

int main() {
    struct queue q;
    q.front = q.rear = NULL;
    int pilih;
    menu();
    while(1) {
        printf("\n1. Input data penumpang\n2. Hapus data penumpang\n3. Menampilkan data penumpang\n4. Keluar dari program\nPilih menu: ");
        scanf("%d", &pilih);
        switch(pilih) {
            case 1:
                enqueue(&q);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Terima kasih telah menggunakan program kami!");
                exit(0);
            default:
                printf("\nAnda memilih salah menu! Silahkan memilih ulang. (Pilihan hanya 1 s.d. 4)");
        }
    }
    return 0;
}

