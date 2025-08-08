#include <conio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void reverse(char str[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void swapBrackets(char str[])
{
int i;
    for ( i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    char postfix[SIZE], revInfix[SIZE];
    int i = 0, j = 0;

    strcpy(revInfix, infix);
    reverse(revInfix);
    swapBrackets(revInfix);

    for (i = 0; revInfix[i]; i++)
    {
        char c = revInfix[i];

        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); 
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    reverse(postfix);
    strcpy(prefix, postfix);
}

void main()
{
    char infix[SIZE], prefix[SIZE];
    clrscr();

    printf("Enter Infix Expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s", prefix);

    getch();
}