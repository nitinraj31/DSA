// implemnetation of a simple queue using array in program
// give  me the address of queue.c file when progeam started 

#include <stdio.h>
#include <stdlib.h> 
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue();
void pop();
void display();
void enqueue()
{
    int value;
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
    }
}

void pop()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
    }
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
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