#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE_LIMIT 1000

static long top = -1;
static unsigned int stack[MAX_SIZE_LIMIT];

void push(unsigned int element);
void pop(void);
void print(void);

int main()
{
    unsigned int choice = 0;
    unsigned int element = 0;
    unsigned int position;
    while (1)
    {
        /* User interaction code*/
        printf("\nSelect the option\n1.Push element\n2.Pop element\n3.Print current stack\n4.Get top element\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed\n");
            scanf("%d", &element);
            push(element);
            break;
        case 2:

            pop();

            break;
        case 3:
            print();
            break;
        case 4:
            printf("The top element is %d\n", stack[top]);
            break;
        case 5:
            return 0;
            break;

        default:
            //return 0;
            printf("Wrong input\n");
            break;
        }
    }
    return 0;
}

void push(unsigned int element)
{
    if (top >= MAX_SIZE_LIMIT)
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = element;
    return;
}

void pop(void)
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return;
    }
    top--;
    printf("The popped element is %d", stack[top + 1]);
    return;
}

void print(void)
{
    for (int i = top; i >=0; i--)
    {
        printf("\n%d", stack[i]);
    }
}