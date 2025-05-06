#include <stdio.h>
#include <stdlib.h> 
#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

struct stack 
{
    int item[STACKSIZE];
    int top;
};

void init(struct stack*);
void push(struct stack*, int x);
int pop(struct stack*);
int empty(struct stack*);
int stacktop(struct stack);

void main() 
{
    struct stack s;
    int c, x;
    char ch;

    init(&s); 

    start:
    printf("\n1. Initialisation of stack\n");
    printf("2. Insertion in the stack\n");
    printf("3. Removal from the stack\n");
    printf("4. Displaying the top element of the stack\n");
    printf("5. Exit\n");
    printf("===========================\n");
    printf("Enter your choice: ");
    scanf("%d", &c);

    switch (c) 
    {
        case 1: 
            init(&s); 
            printf("\nStack initialized successfully!\n");
            break;
        case 2: 
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &x);
            push(&s, x); 
            break;
        case 3: 
            if (!empty(&s)) 
            {
                x = pop(&s);
                printf("\nRemoved item is: %d\n", x);
            } 
            else 
            {
                printf("\nStack is empty. Cannot remove an element.\n");
            }
            break;
        case 4: 
            if (!empty(&s)) 
            {
                x = stacktop(s);
                printf("\nStack top item is: %d\n", x);
            } 
            else 
            {
                printf("\nStack is empty.\n");
            }
            break;
        case 5: 
            exit(0);
        default: 
            printf("\nWrong choice!\n"); 
            break;
    }

    printf("\nDo you wish to continue? (y/n): ");
    fflush(stdin);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto start;
}

void init(struct stack *s) {
    s->top = -1;
}

int empty(struct stack *s) 
{
    if(s->top == -1) 
    return TRUE ;
    else
    return FALSE;
}

void push(struct stack *s, int x) 
{
    if (s->top == STACKSIZE - 1) 
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->top++;  
    s->item[s->top] = x;  
}

int pop(struct stack *s) 
{
    int y;
    if (empty(s)) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    y = s->item[s->top];
    s->top--;
    return y;
}

int stacktop(struct stack s) 
{
    int y;
    y=s.item[s.top];
    return y;
}