/* Write a program to Implementation of Stack using array.
 */

#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
int stack[5];
int top = -1;
int main()
{
    int choice;
    do
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    } while (choice != 4);
    push();
    pop();
    display();
}
void push()
{
    int element = 92;

    if (top < 4)
    {
        printf("Enter the Element");
        scanf("%d", &element);
        top = top + 1;
        stack[top] = element;
    }
    else
    {
        printf("Stack is overflow");
    }
}
void pop()
{
    if (top >= 0)
    {
        int element;
        element = stack[top];
        top = top - 1;
        printf("deleted %d", element);
    }
    else
    {
        printf("Stack underfolw");
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("Element are %d", stack[i]);
        }
    }
}
