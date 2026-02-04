// implementation of a simple queue using array in C
// program to check addresses of queue, elements, and variables

#include <stdio.h>
#include <stdlib.h> 

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue();
void pop();
void display();
void showAddresses();

void enqueue()
{
    int value;

    printf("Address of local variable 'value': %p\n", (void*)&value);

    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        queue[++rear] = value;

        printf("%d enqueued into queue\n", value);
        printf("Stored at address: %p\n", (void*)&queue[rear]);
    }
}

void pop()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("%d dequeued from queue\n", queue[front]);
        printf("Address of dequeued element: %p\n", (void*)&queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements with addresses:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("Value: %d  Address: %p\n", queue[i], (void*)&queue[i]);
        }
    }
}

void showAddresses()
{
    printf("\n--- MEMORY ADDRESS INFO ---\n");
    printf("Base address of queue array      : %p\n", (void*)queue);
    printf("Address of front variable        : %p\n", (void*)&front);
    printf("Address of rear variable         : %p\n", (void*)&rear);

    if (front != -1 && front <= rear)
    {
        printf("Front element address            : %p\n", (void*)&queue[front]);
        printf("Rear element address             : %p\n", (void*)&queue[rear]);
    }
    else
    {
        printf("Queue is empty, no element addresses\n");
    }
}

int main()
{
    printf("Program started...\n");
    printf("Address of queue array (queue.c): %p\n", (void*)queue);

    int choice;
    char ch;

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Show Addresses\n5. Exit\n");
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
                showAddresses();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
