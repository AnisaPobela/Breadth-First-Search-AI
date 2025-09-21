#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Struktur Node untuk Queue
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

/* Inisialisasi queue kosong */
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

/* Mengecek apakah queue kosong */
int isEmpty(Queue *q) {
    return q->rear == -1;
}

/* Enqueue (memasukkan elemen baru ke queue) */
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue penuh!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

/* Dequeue (mengeluarkan elemen dari depan queue) */
int dequeue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue kosong!\n");
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Graph menggunakan adjacency list
int adj[MAX][MAX];
int visited[MAX];
int n; // jumlah node

/* Fungsi utama BFS */
void bfs(int startNode) {
    Queue q;
    initQueue(&q);

    visited[startNode] = 1;
    enqueue(&q, startNode);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 1; i <= n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

/*Menentukan jumlah node n = 8*/
int main() {
    n = 8; // jumlah node

    // Inisialisasi adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Tambah edge sesuai tree di modul
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][5] = adj[5][4] = 1;
    adj[4][6] = adj[6][4] = 1;
    adj[5][7] = adj[7][5] = 1;
    adj[6][8] = adj[8][6] = 1;

    printf("Hasil BFS mulai dari node 1:\n");
    bfs(1);

    return 0;
}
