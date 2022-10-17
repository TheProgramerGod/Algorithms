#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} node;

node *create(node *p, int d)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = d;
    new->link = NULL;

    p->link = new;
    return new;
}

node *add_at_beg(node *head, int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->link = NULL;

    temp->link = head;
    head = temp;
    return head;
}

void del_pos(node **head, int position)
{
    node *current = *head;
    node *previous = *head;
    if (head == NULL)
        printf("List is empty!");
    else if (position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

void display(node *ptr)
{
    while (ptr->link != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("%d", ptr->data);
}

int main()
{
    int n, x, choice1, choice2, y, pos;
    printf("\nEnter your choice, Press 1 to enter and press 0 to exit : ");
    scanf("%d", &choice1);
    node *head = NULL;
    while (choice1 != 0)
    {
        printf("\nEnter the operation you want to perform:\n1.Creation of the linked list\n2.Insertion at the begining of the list\n3.Deleting a node from a specific position\n4.Display the linked list");
        printf("\nEnter your choice : ");
        scanf("%d", &choice2);

        switch (choice2)
        {
        case 1:
            printf("Enter the number of node you want to create : ");
            scanf("%d", &n);
            printf("\nEnter data for %d node : ", 1);
            scanf("%d", &x);
            head = (node *)malloc(sizeof(node));
            head->data = x;
            head->link = NULL;
            node *ptr = head;
            for (int i = 1; i < n; i++)
            {
                printf("Enter data for %d node : ", (i + 1));
                scanf("%d", &x);
                ptr = create(ptr, x);
            }
            ptr = head;
            break;
        case 2:
            if (head == NULL)
                printf("Link list not created!!");
            else
            {
                printf("\nEnter the data you want to enter at the begining of the list : ");
                scanf("%d", &y);
                head = add_at_beg(head, y);
                n++;
                ptr = head;
            }
            break;
        case 3:
            printf("\nEnter the position you want to delete the node : ");
            scanf("%d", &pos);
            if (n < pos || pos == 0)
                printf("\nEnter a valid position");
            else
            {
                del_pos(&ptr, pos);
            }
            ptr = head;
            break;
        case 4:
            if (head == NULL)
                printf("Linked list not created!!");
            else
            {
                printf("\nThe linked list is : ");
                display(ptr);
            }
            break;
        default:
            printf("\nInvalid Input!!");
            break;
        }
        printf("\nDo you want to continue ? ");
        scanf("%d", &choice1);
    }
    return 0;
}