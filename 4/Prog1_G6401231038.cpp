#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100
#define TRUE 1
#define FALSE 0

struct stack {
    int item[STACKSIZE];
    int top;
};

void init(struct stack*);
void push(struct stack*, int x);
int pop(struct stack*);
int empty(struct stack*);
int stacktop(struct stack);

void init(struct stack *s) {
    s->top = -1;                // Pertanyaan 1
}

int empty(struct stack *s) {
    if (s->top == -1)           // Pertanyaan 2
        return TRUE;
    else
        return FALSE;
}

void push(struct stack *s, int x) {
    if (s->top == STACKSIZE - 1) {      // Pertanyaan 3
        printf("stack overflow");
        exit(1);
    }
    s->top++;                           // Pertanyaan 4
    s->item[s->top] = x;
}

int pop(struct stack *s) {
    int y;
    if (empty(s)) {
        printf("Stack Underflows");
        exit(1);
    }
    y = s->item[s->top];
    s->top--;                           // Pertanyaan 5
    return (y);
}

int stacktop(struct stack s) {
    int y;
    if (empty(&s)) {
        printf("Stack is empty");
        exit(1);
    }
    y = s.item[s.top];
    return (y);
}

int main() {
    struct stack s;
    int c, x;
    char ch;

    start:
    printf("1. Initialisation of stack\n");
    printf("2. Insertion in the stack\n");
    printf("3. Removal from the stack\n");
    printf("4. Displaying the top Element of the stack\n");
    printf("5. exit\n");
    printf("===========================\n");
    printf("Enter your choice\t");
    scanf("%d", &c);

    switch (c) {
        case 1: init(&s); break;
        case 2:
            printf("\nEnter the element to be inserted");
            scanf("%d", &x);
            push(&s, x);
            break;
        case 3:
            x = pop(&s);
            printf("\nRemoved item is:=> \t%d", x);
            break;
        case 4:
            x = stacktop(s);
            printf("\nStacktop item is:=> \t%d", x);
            break;
        case 5: exit(1);
        default: printf("\nWrong choice"); break;
    }

    printf("\nDo you wish to continue? (y/n) \n");
    fflush(stdin);
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto start;
}

// int main() {
//     struct stack s;
//     init(&s);

//     push(&s, 4);
//     push(&s, 8);
//     printf("Menghapus: %d\n", pop(&s));
//     push(&s, 6);
//     push(&s, 19);
//     printf("Menghapus: %d\n", pop(&s));
//     printf("Menghapus: %d\n", pop(&s));
//     push(&s, 8);

//     printf("Isi stack: ");
//     for (int i = 0; i <= s.top; i++) {
//         printf("%d ", s.item[i]);
//     }
//     printf("\n");

//     return 0;
// }
