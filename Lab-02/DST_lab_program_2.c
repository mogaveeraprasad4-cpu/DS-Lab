#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    int i = 0, k = 0;
    char ch;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
        {
            push(ch);
        }
        else if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[k++] = pop();
            }

            pop();   // remove '('
        }
        else
        {
            while (precedence(stack[top]) >= precedence(ch))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }
    }

    while (stack[top] != '#')
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix Expression = %s\n", postfix);

    return 0;
}