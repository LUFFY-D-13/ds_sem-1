#include<stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push()
{
    int value;
    if (top == SIZE - 1)
    {
	printf("Stack Overflow\n");
    }
    else
    {
	printf("Enter value to push: ");
	scanf("%d", &value);
	stack[++top] = value;
	printf("%d pushed into the stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
	printf("Stack Underflow! Cannot pop.\n");
    }
    else
    {
	printf("Popped %d from the stack.\n", stack[top--]);
    }
}

void peep()
{
    int i,value, found = 0;
    if (top == -1)
    {
	printf("Stack is Empty! Cannot search.\n");
	return;
    }

    printf("Enter value to search in stack: ");
    scanf("%d", &value);

    for (i = top; i >= 0; i--)
    {
	if (stack[i] == value)
	{
	    printf("Element %d found at position %d from top.\n", value, top - i + 1);
	    found = 1;
	    break;
	}
    }

    if (!found)
    {
	printf("Element %d not found in the stack.\n", value);
    }
}

void display()
{
    if (top == -1)
    {
	printf("Stack is Empty!\n");
    }
    else
    {
    int i;
	printf("Stack elements are: ");
	for (i = top; i >= 0; i--)
	{
	    printf("%d ", stack[i]);
	}
	printf("\n");
    }
}

void main()
{
    int choice;
    clrscr();

    while (1)
    {
	printf("\nStack Menu\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peep/Search (Search by Value)\n");
	printf("4. Display Stack\n");
	printf("5. Exit\n");
	printf("Enter your choice (1-5): ");
	scanf("%d", &choice);
	clrscr();

	switch (choice)
	{
	case 1:
	    push();
	    break;
	case 2:
	    pop();
	    break;
	case 3:
	    peep();
	    break;
	case 4:
	    display();
	    break;
	case 5:
	    printf("Exiting Program.\n");
	    getch();
	    exit(0);
	default:
	    printf(" Please enter 1-5.\n");
	}
    }


}