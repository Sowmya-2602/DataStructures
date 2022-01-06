#include<stdio.h>
#include<stdlib.h>



typedef struct _stackMenu
{
    int *stack;
    int top;
    int size;
}stackMenu;

void push(stackMenu *sp, int value);
int pop(stackMenu *sp);
void init(stackMenu *sp, int size);

void init(stackMenu *sp, int size)
{
    sp->top = -1;
    sp->size = size;
    sp->stack = (int *) malloc(sizeof(int)*sp->size);
    if(sp->stack == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void dealloc(stackMenu *sp)
{
    if(sp->stack != NULL)
    {
        free(sp->stack);
    }
    
}

void push(stackMenu *sp, int value)
{
    if(sp->top == (sp->size-1))
    {
        printf("Stack Overflow");
    }
    sp->top++;
    sp->stack[sp->top] = value;
    printf("Top=%d",sp->top);

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
    init(&s1, 4);
    int Choice, value;
    printf("operations: ");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
    
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
            case 3:
                   dealloc(&s1);
                   exit(0);
            default:
                   printf("Invalid Choice\n");

        }

    }
}

