#include <conio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
	printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%d removed from queue.\n", queue[front]);
        front++;
    }
}


void display()
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


void modify(int oldValue, int newValue)
{
    int i, found = 0;
    for (i = front; i <= rear; i++)
    {
        if (queue[i] == oldValue)
        {
            queue[i] = newValue;
            found = 1;
            printf("Value %d modified to %d.\n", oldValue, newValue);
            break;
        }
    }
    if (!found)
    {
        printf("Value %d not found in the queue.\n", oldValue);
    }
}


void main()
{
    int choice, value, oldValue, newValue;
    clrscr(); 

    while (1)
    {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Modify\n5. Exit\n");
        printf("Enter your choice: ");
	scanf("%d", &choice);
	clrscr();

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter value to modify: ");
            scanf("%d", &oldValue);
            printf("Enter new value: ");
            scanf("%d", &newValue);
            modify(oldValue, newValue);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }


}