/* Write a program Implementation the following data structures :Singly linked list.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insertatbegin(int);
void insertatend(int);
void insertinbetween(int, int, int);
void deleteatbegin();
void deleteatend();
void deleteinbetween(int);
void search(int);
void display();

int main()
{
    int choice;
    do
    {
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert in between\n4. delete at Beginning\n5. Delete at End\n6. Delete in Between\n7. Search\n8. Display\n9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int element;
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &element);
            insertatbegin(element);
            break;
        case 2:
            printf("Enter the element : ");
            scanf("%d", &element);
            insertatend(element);
            break;
        case 3:
            printf("Enter the element: ");
            scanf("%d", &element);
            printf("\nInsert two locations: ");
            int loc1, loc2;
            scanf("%d%d", &loc1, &loc2);
            insertinbetween(element, loc1, loc2);
            break;
        case 4:
            deleteatbegin();
            break;
        case 5:
            deleteatend();
            break;
        case 6:
            printf("Enter the element: ");
            scanf("%d", &element);
            deleteinbetween(element);
            break;
        case 7:
            printf("Enter the element: ");
            scanf("%d", &element);
            search(element);
            break;
        case 8:
            printf("the elements of the ll are: ");
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Enter the correct choice.");
            break;
        }
    } while (choice != 9);
    return 0;
}

void insertatbegin(int element)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("\nNode inserted\n");
}

void insertinbetween(int element, int loc1, int loc2)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->data != loc1 && temp->data != loc2)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("\nNode inserted successfully");
}

void insertatend(int element)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteatbegin()
{
    if (head == NULL)
    {
        printf("\nThe list is empty.\n");
    }
    else
    {
        struct Node *temp;
        temp = head;
        if (head->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            free(temp);
        }
        printf("\nDeletion Successful\n");
    }
}

void deleteatend()
{
    if (head == NULL)
    {
        printf("\nThe list is empty.\n");
    }
    else
    {
        struct Node *temp = head, *temp2;
        if (head->next == NULL)
        {
            head == NULL;
            free(temp);
        }
        else
        {
            while (temp->next != NULL)
            {
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = NULL;
        }
        free(temp);
    }
}

void deleteinbetween(int element)
{
    if (head == NULL)
    {
        printf("\nThe list is empty.\n");
        goto functionEnd;
    }
    else if (head->next == NULL)
    {
        printf("\nThe element not found.\n");
        goto functionEnd;
    }
    else
    {
        struct Node *temp = head, *temp2;
        while (temp->data != element)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        free(temp);
    }
functionEnd:
    printf("\nOne node is deleted \n");
}

void search(int element)
{
    if (head == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        if (head->next == NULL)
        {
            if (head->data == element)
            {
                printf("\nSearch successful!!!\n");
            }
            else
            {
                printf("\nunsuccessful!!\n");
            }
        }
        else
        {
            struct Node *temp = head;
            while (temp->next != NULL && temp->data != element)
            {
                temp = temp->next;
            }
            if (temp->data == element)
            {
                printf("\nSearch successful!!!\n");
            }
            else
            {
                printf("\nunsuccessful!!\n");
            }
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            printf("%d ---> ", temp->data);
            temp = temp->next;
        }
        printf("%d---->NULL", temp->data);
        printf("\n");
    }
}
