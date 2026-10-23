#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q) {
    return (q->front == q->rear);
}

bool isFull(Queue *q) {
    return (q->rear + 1 == MAX_SIZE);
}

void addQ(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

void delQ(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    q->front++;
    printf("delQd %d from the queue.\n", q->items[q->front]);
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front + 1];
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Current Queue: ");
    for (int i = q->front + 1; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. addQ\n");
        printf("2. delQ\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to addQ: ");
                scanf("%d", &value);
                addQ(&q, value);
                break;

            case 2:
                delQ(&q);
                break;

            case 3: {
                int frontVal = peek(&q);
                if (frontVal != -1 || !isEmpty(&q)) {
                    printf("Front element: %d\n", frontVal);
                }
                break;
            }

            case 4:
                printQueue(&q);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select an option from 1 to 5.\n");
        }
    }

    return 0;
}