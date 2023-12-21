#include <stdio.h>

struct queue {
	int data;
    int priority;
}
q[100];

int front = -1, rear = -1, size;

void enqueue(int d, int p){
    if (rear == size - 1) 
        printf("Queue is full\n");
    else {
        if (front == -1) {
            front = 0;
            q[++rear].data = d;
            q[rear].priority = p;
        } else {
            struct queue temp;
            q[++rear].data = d;
            q[rear].priority = p;
            for (int i = rear; i > front; i--) {
                if (q[i].priority < q[i - 1].priority) {
                    temp = q[i];
                    q[i] = q[i - 1];
                    q[i - 1] = temp;
                }
            }
        }
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Deleted element: %d\n", q[front].data);
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display() {
    if (front == -1)
        printf("\nQueue: Empty Queue\n"); 
    else {
        printf("\nQueue: ");
        for (int i = front; i <= rear; i++)
            printf("%d\t", q[i].data);
        printf("\n");
    }
}

void main() {
    int o, d, p;
    printf("Enter The Size of The Queue: ");
    scanf("%d", &size);

	printf("\n\t\t ============= MENU =============");
    printf("\n\t\t 1) Enqueue");
    printf("\n\t\t 2) Dequeue");
    printf("\n\t\t 3) Exit");
    printf("\n\t\t ================================\n");

    while (o != 3) {
        display();

		printf("\nEnter Your Option: ");
        scanf("%d", & o);
        switch (o) {
        case 1:
            printf("Enter The Data And Priority: ");
            scanf("%d %d", & d, & p);
            enqueue(d, p);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Closing...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
}