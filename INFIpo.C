#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
	return '!';
    return stack[top--];
}

int priority(char ch) {
    if (ch == '(')
	return 0;
    if (ch == '+' || ch == '-')
	return 1;
    if (ch == '*' || ch == '/')
	return 2;
    return -1;
}

void main() {
    char exp[MAX];
    int i;
    char ch;

    clrscr();

    printf("Enter infix expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");

    for (i = 0; exp[i] != '\0'; i++) {
	ch = exp[i];

	if (isalnum(ch)) {
	    printf("%c ", ch);
	} else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                printf("%c ", pop());
            }
	    pop();
	} else {
	    while (top != -1 && priority(stack[top]) >= priority(ch)) {
		printf("%c ", pop());
	    }
	    push(ch);
	}
    }

    while (top != -1) {
	printf("%c ", pop());
    }

    getch();
}
