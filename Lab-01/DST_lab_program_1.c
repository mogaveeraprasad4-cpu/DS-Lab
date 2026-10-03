#include<stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push()
{
    int x;
    if(top == MAX-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        printf("enter value : ");
        scanf("%d",&x);
        stack[++top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d popped from stack\n",stack[top--]);
    }
}
void peep()
{
    if(top==-1)
    {
        printf("stack empty\n");
    }
    else
    {
        printf("top %d",stack[top]);
    }
}void display()
{
    if(top==-1)
    {
        printf("stack empty\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
            printf("%d ",stack[i]);
        printf("\n");

    }
}
int main()
{
    int ch;
    while(1)
    {
        printf(" 1.push\n 2.pop\n 3.peek\n 4.display\n 5.exit\n");
        printf("Choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peep();
            break;
            case 4:display();
            break;
            case 5:return 0;
            default:printf("invalid choice:");
        }
    }
}