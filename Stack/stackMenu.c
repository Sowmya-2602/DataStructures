#include <stdio.h>

#define SIZE 10

typedef struct _stackMenu
{
    int stack[SIZE];
    int top;
}stackMenu;

void push(stackMenu *sp, int value);
int pop(stackMenu *sp);
void init(stackMenu *sp);

void init(stackMenu *sp)
{
    sp->top = -1;
}

void push(stackMenu *sp, int value)
{
    if(sp->top == SIZE-1)
    {
        printf("Stack Overflow");
    }
    sp->top++;
    sp->stack[sp->top] = value;

}

int pop(stackMenu *sp)
{
    int value;

    if(sp->top == -1)
    {
        printf("Stack Underflow");
        return -9999;
    }

    value = sp->stack[sp->top];
    sp->top--;
    return value;
}

int main()
{
    stackMenu s1;
    init(&s1);
    int Choice, value;
    printf("operations: ");
    printf("1. Push\n");
    printf("2. Pop\n");
    
    while(1)
    {
        printf("Enter Choice: ");
        scanf("%d", &Choice);
        switch(Choice)
        {
            case 1:
                   printf("Enter Value to be pushed\n");
                   scanf("%d", &value);
                   push(&s1, value);
                   break;
            case 2:
                   value = pop(&s1);
                   if(value != -9999)
                   {
                        printf("popped value is: %d\n ", value);

                   }
                   break;
            default:
                   printf("Invalid Choice\n");

        }

    }
}

