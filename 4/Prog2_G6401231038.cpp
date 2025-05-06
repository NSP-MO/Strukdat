#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 5
#define TRUE 1
#define FALSE 0

struct queue {
    int item[MAXQUEUE];
    int front;
    int rear;
};

void init(struct queue* pq);
void insert(struct queue* pq, int x);
int remov(struct queue* pq);
int empty(struct queue* pq);

void init(struct queue* pq) {
    pq->rear = -1;
    pq->front = 0;
}

void insert(struct queue* pq, int x) {
    if (pq->rear == MAXQUEUE - 1) {         // Pertanyaan 6
        printf("Queue Overflows\n");
        exit(1);
    }
    pq->rear++;                             // Pertanyaan 7
    pq->item[pq->rear] = x;
}

int remov(struct queue* pq) {
    int x;
    if (empty(pq)) {
        printf("Queue Underflows\n");
        exit(1);
    }
    x = pq->item[pq->front];
    pq->front++;                            // Pertanyaan 8
    return x;
}

int empty(struct queue* pq) {
    if (pq->front == 0 && pq->rear == -1)
        return TRUE;
    else
        return FALSE;
}

int main() {
    struct queue q;
    int x, c;
    char ch;

    init(&q);

    do {
        printf("1. Initialise the queue\n");
        printf("2. Insert in the queue\n");
        printf("3. Remove from the queue\n");
        printf("4. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                init(&q);
                break;
            case 2:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &x);
                insert(&q, x);
                break;
            case 3:
                x = remov(&q);
                printf("\nRemoved item is: %d\n", x);
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice\n");
                break;
        }

        printf("\nDo you wish to continue? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

// int main() {
//     struct queue q;
//     init(&q);

//     insert(&q, 4);      // Rear = 0, front = 0
//     insert(&q, 8);      // Rear = 1, front = 0
//     insert(&q, 6);      // Rear = 2, front = 0
//     insert(&q, 19);     // Rear = 3, front = 0
//     insert(&q, 8);      // Rear = 4, front = 0

//     remov(&q);          // Rear = 4, front = 1
//     remov(&q);          // Rear = 4, front = 2
//     remov(&q);          // Rear = 4, front = 3
//     remov(&q);          // Rear = 4, front = 4

//     printf("Setelah operasi:\nFront: %d, Rear: %d\n\n", q.front, q.rear);

//     insert(&q, 11);     // Rear = 5, front = 4  (Queue Overflows)

//     return 0;
// }

