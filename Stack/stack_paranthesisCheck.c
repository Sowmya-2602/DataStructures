#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



typedef struct _stackMenu
{
    char *stack;
    int top;
    int size;
    
}stackMenu;

void push(stackMenu *sp, char value);
char pop(stackMenu *sp);
void init(stackMenu *sp, int size);
int  getSize(stackMenu *sp);
void dealloc(stackMenu *sp);
void printBinaryEq(unsigned int);
void paranthesisCheck(stackMenu *sp, char *exp);

void paranthesisCheck(stackMenu *sp, char *exp)
{
    bool error = false;
    int i = 0;
    printf("i= %d and c = %c ",i,exp[i]);
    while(exp[i] != '\0')
    {      
        if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
        {
            push(sp, exp[i]);
        }
        else if((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}'))
        {
            if(sp->top== -1)
            {
                error = true;
                printf(" error empty");
                break;
            }
            else
            {
                switch(exp[i])
                {
                    case ')': if(sp->stack[sp->top] == '(')
                              {
                                  pop(sp);
                                  //printf("()");
                              }
                              else
                              {
                                  error = true;
                                  //printf(" error )");
                              }
                              break;
                    case ']': if(sp->stack[sp->top] == '[')
                              {
                                  pop(sp);
                                 // printf("[]");
                              }
                              else
                              {
                                  error = true;
                                  //printf(" error ]");
                              }
                              break;
                    case '}': if(sp->stack[sp->top] == '{')
                              {
                                  pop(sp);
                                  //printf("{}");
                              }
                              else
                              {
                                  error = true;
                                  //printf(" error }");
                              }
                              break;
                    default:
                            break;
                }
                if(error == true)
                {
                    printf("Error in the expression");
                    break;
                }
           }
        }
        i++;   
    }
    if(error == false)
    {
        if(sp->top != -1)
        {
            error = true;
            printf("Error in the expression");
        }
        else
        {
            printf("No Error in the expression");
        }        
    }
}

void printBinary(unsigned int n)
{
    int rem, temp = n;
    stackMenu S;
    init(&S, 10);

    while(n>0)
    {
        rem = n%2;
        push(&S, rem);
        n /= 2;
    }
    printf("Binary equivalent of %d is ", temp);

    while(S.top != -1)
    {
        printf("%d", pop(&S));
    }
    dealloc(&S);
}
int getSize(stackMenu *sp)
{
    int size;
    size = sp->size;
    return size;
}

void init(stackMenu *sp, int size)
{
    sp->top = -1;
    sp->size = size;
    sp->stack = (char *) malloc(sizeof(char)*sp->size);
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

void push(stackMenu *sp, char value)
{
    if(sp->top == (sp->size-1))
    {
        char *temp;
        temp = (char *) malloc(sizeof(char) *sp->size*2);
        if(temp == NULL)
        {
            printf("Stack Overflow");
        }
        else
        {
            int i;
            for(i = 0; i<=sp->top; i++)
            {
                sp->stack[i] = temp[i];
            }
            free(sp->stack);
            //temp;
            sp->size *= 2;
        }
        
    }
    sp->top++;
    sp->stack[sp->top] = value;
   // printf("Top=%d",sp->top);
}

char pop(stackMenu *sp)
{
    char value;

    if(sp->top == -1)
    {
        printf("Stack Underflow");
        return 0;
    }
    value = sp->stack[sp->top];
    sp->top--;
    return value;
}

int main()
{
    stackMenu s1;
    init(&s1, 10);
    char exp[25] = "2*[(3+4)+(5*6)]\0";
    paranthesisCheck(&s1, &exp[0]);   
}

