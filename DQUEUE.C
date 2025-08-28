#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 8

int deque[SIZE];
int front = -1, rear = -1;

void enqueueRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Queue is full at rear!\n");

    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
	rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

void enqueueFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full at front!\n");

    }

    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
	front = SIZE - 1;
    } else {
	front--;
    }
    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

void dequeueFront() {
    if (front == -1) {
	printf("Queue is empty!\n");
	return;
    }
    printf("%d removed from front.\n", deque[front]);

    if (front == rear) {
	front = rear = -1;
    } else if (front == SIZE - 1) {
	front = 0;
    } else {
	front++;
    }
}

void dequeueRear() {
    if (front == -1) {
	printf("Queue is empty!\n");

    }
    printf("%d removed from rear.\n", deque[rear]);

    if (front == rear) {
	front = rear = -1;
    } else if (rear == 0) {
	rear = SIZE - 1;
    } else {
	rear--;
    }
}

void display() {
    int i;
    if (front == -1) {
	printf("Queue is empty!\n");

    }
    printf("Queue elements: ");
    i = front;
    while (1) {
	printf("%d ", deque[i]);
	if (i == rear)
	    break;
	i = (i + 1) % SIZE;
    }
    printf("\n");
}

void modify() {
    int count, index, newValue;
	 if (front == -1) {
	printf("Queue is empty! Cannot modify.\n");
	}

	if (rear >= front)
		count = rear - front + 1;
	 else
		count = SIZE - front + rear + 1;

	printf("Enter the index to modify: ", count - 1);
	scanf("%d", &index);

		 if (index < 0 || index >= count) {
		      printf("Invalid index!\n");

    }

	  printf("Enter new value: ");
	  scanf("%d", &newValue);

	  deque[(front + index) % SIZE] = newValue;
	  printf("Value at index %d modified to %d.\n", index, newValue);
}

void main() {
    int choice, value;

    while (1) {
	clrscr();
	printf("\nDouble Queue Menu:\n");
	printf("1. Enqueue at Rear\n2. Enqueue at Front\n");
	printf("3. Dequeue from Front\n4. Dequeue from Rear\n");
	printf("5. Display\n6. Modify\n");
	printf("7. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter value to insert at rear: ");
		scanf("%d", &value);
		enqueueRear(value);
		break;
	    case 2:
		printf("Enter value to insert at front: ");
		scanf("%d", &value);
		enqueueFront(value);
		break;
	    case 3:
		dequeueFront();
		break;
	    case 4:
		dequeueRear();
		break;
	    case 5:
		display();
		break;
	    case 6:
		modify();
		break;
	    case 7:
		return;
	    default:
		printf("Invalid choice! Try again.\n");
	}

		 getch();
    }
}
