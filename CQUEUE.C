#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void insert() {
    int val;
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full\n");

    }

    printf("Enter value: ");
    scanf("%d", &val);

    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    cq[rear] = val;
    printf("Inserted: %d\n", val);
}

void removeElement() {
    if (front == -1) {
	printf("Queue is empty\n");
    }

    printf("Removed: %d\n", cq[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void modify() {
    int pos, val, idx, count = 0;

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Enter position in queue (1-based index): ");
    scanf("%d", &pos);

    idx = front;
    while (1) {
        count++;
        if (count == pos) {
            printf("Current value: %d\n", cq[idx]);
            printf("Enter new value: ");
            scanf("%d", &val);
            cq[idx] = val;
            printf("Value modified.\n");
            return;
        }
        if (idx == rear)
            break;
        idx = (idx + 1) % SIZE;
    }

    printf("Invalid position\n");
}

void main() {
    int choice;
    clrscr();

    while (1) {
	printf("\n--- Circular Queue Menu ---\n");
	printf("1. Insert\n2. Remove\n3. Display\n4. Modify\n5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	clrscr();

	switch (choice) {
	    case 1:
		insert();
		break;
	    case 2:
		removeElement();
		break;
	    case 3:
		display();
		break;
	    case 4:
		modify();
		break;
	    case 5:
		exit(0);
	    default:
		printf("Invalid choice\n");
	}
	 getch();
    }


}
