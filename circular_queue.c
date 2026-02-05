// write a circular queue in c with memory addresses of each element
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue()
{
    int value;
    if ((rear + 1) % MAX == front)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        if (front == -1)
            front = rear;
        printf("%d enqueued into queue\n", value);
        printf("Stored at address: %p\n", (void*)&queue[rear]);
    }
}
void pop()
{
    if (front == -1)
        printf("Queue Underflow\n");
    else
    {
        printf("%d dequeued from queue\n", queue[front]);
        printf("Address of dequeued element: %p\n", (void*)&queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}
void display()
{
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements with addresses:\n");
        int i = front;
        while (1)
        {
            printf("Value: %d  Address: %p\n", queue[i], (void*)&queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
    }
}
int main()
{
    int choice;
    char ch;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
    