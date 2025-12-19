// Menu derived from stack.c
// Design Until that user wants to exit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push()
{
    int value;
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the value to be pushed: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

void pop()
{
    int n;
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        n = stack[top];
        top--;
        printf("%d popped from stack\n", n);
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("------------------Stack Operations------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: 
            push();
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
            break;
        }
    }
}