#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push()
{
    int value;
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d popped from stack\n", stack[top--]);
}

void display()
{
    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;
    char ch;

    do
    {
        printf("\n------ Stack Operations ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: 
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    printf("Program terminated by user.\n");
    return 0;
}
