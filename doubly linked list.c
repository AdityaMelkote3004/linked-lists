#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = NULL; 
    while (1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: {
                printf("Enter data for the node: ");
                int data;
                scanf("%d", &data);
                insert_beg(&head, data);
                break;
            }
            case 2: {
                printf("Enter data for the node: ");
                int data;
                scanf("%d", &data);
                insert_end(&head, data);
                break;
            }
            case 3: {
                printf("Enter data for the node: ");
                int data;
                scanf("%d", &data);
                printf("Enter position: ");
                int pos;
                scanf("%d", &pos);
                insert_pos(&head, data, pos);
                break;
            }
            case 4: {
                delete_beg(&head);
                break;
            }
            case 5: {
                delete_end(&head);
                break;
            }
            case 6: {   
                printf("Enter position: ");
                int pos;
                scanf("%d", &pos);
                delete_pos(&head, pos);
                break;
            }
            case 7: {
                print_list(head);
                break;
            }
            case 8: {
                exit(0);
            }
            default: {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
    }
    return 0;
}

void insert_beg(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void insert_end(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    struct node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->prev = ptr;
}

void insert_pos(struct node **head, int data, int pos)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (pos == 1)
    {
        new_node->prev = NULL;
        new_node->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }
    struct node *current = *head;
    for (int i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Position out of bounds\n");
        free(new_node);
    }
    else
    {
        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != NULL)
        {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }
}

void delete_beg(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delete_end(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    if (current->prev != NULL)
    {
        current->prev->next = NULL;
    }
    free(current);
}

void delete_pos(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *current = *head;
    for (int i = 1; i < pos && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
}

void print_list(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = head;
    printf("List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}