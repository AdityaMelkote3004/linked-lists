#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}; 

void insert_beg(struct node **head, int data);
void insert_end(struct node **head, int data);
void insert_pos(struct node **head, int data, int pos);
void delete_beg(struct node **head);
void delete_end(struct node **head);
void delete_pos(struct node **head, int pos);
void print_list(struct node *head);

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

// Insert at the beginning
void insert_beg(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Insert at the end
void insert_end(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) { // If the list is empty
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Insert at a specific position
void insert_pos(struct node **head, int data, int pos)
{
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(new_node);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(new_node);
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Delete from the beginning
void delete_beg(struct node **head)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning\n");
}

// Delete from the end
void delete_end(struct node **head)
{
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from the end\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end\n");
}

// Delete from a specific position
void delete_pos(struct node **head, int pos)
{
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted from position 1\n");
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of bounds\n");
    } else {
        struct node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
        printf("Node deleted from position %d\n", pos);
    }
}

// Print the list
void print_list(struct node *head)
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
