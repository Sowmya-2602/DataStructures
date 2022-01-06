
#include<stdio.h>

#define SIZE 10

typedef struct _stack{
    int IndexStack[SIZE];
    int top;
} stack;

//prototypes
extern void init(stack *sp);
extern void push(stack *sp, int value);
extern int pop(stack *sp);


//subroutines
void init(stack *sp)
{
    sp->top = -1 ;
}

void push(stack *sp, int value)
{
    if(sp->top == SIZE-1)
    {
        printf("Stack Overflow");
        return;
    }
    sp->top++;
    sp->IndexStack[sp->top] = value;
}

int pop(stack *sp)
{
    if(sp->top == -1)
    {
        printf("Stack Overflow");
        return 0;
    }
    int value = sp->IndexStack[sp->top];
    sp->top--;
    return value;
}



int main()
{
    stack s1, s2;
    init(&s1);
    init(&s2);
    //init(&sp);
    push(&s1, 100);
    push(&s1, 200);
    push(&s2, 300);
    push(&s2, 400);
   // push(&sp, 100);

    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s1));
    printf("%d\n",pop(&s2));
    printf("%d\n",pop(&s2));

    return 0;
}