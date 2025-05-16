#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void enqueue(){
    int item;
    printf("\nEnter The Element: ");
    scanf("%d", &item);

    if (rear == (MAX - 1)){
        printf("\nQueue Full!\n"); 
    }
    else{
        if ((front == -1) && (rear == -1)){
            front = rear = 0;
            queue[rear] = item;
        }
        else
            queue[++rear] = item;
    }
}

void dequeue(){
    if (front == - 1)
        printf("\nQueue Empty!\n");
    else{
        printf("\nDeleted Value: %d", queue[front]);

        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display(){
    if (front == -1)
        printf("\nQueue Empty!\n");
    else{
        printf("\nQueue:\t");
        for (int i = front; i <= rear; i++)
            printf("%d\t", queue[i]);
    }
}

void main(){
    int menuFlag = 1;
	
    while (menuFlag == 1){
        printf("\n\t\t ============= MENU =============");
        printf("\n\t\t 1) Enqueue");
        printf("\n\t\t 2) Dequeue");
        printf("\n\t\t 3) Display");
        printf("\n\t\t 4) Exit");
        printf("\n\t\t ================================\n");
  
        int o;
        printf("\nEnter Your Option: ");
        scanf("%d", &o);
  
        switch(o){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nClosing...\n");
                menuFlag = 0;
                break;
            default:
                printf("\nPlease Enter A Valid Option!\n");
        }
    }
}