#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    insert_end(head,98);
    insert_end(head,3);

    delete_pos(&head,2);
    print_data(head);
    return 0;

    
}

void insert_beginning(struct node **head, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;
}

void insert_end(struct node *head,int data)
{
    struct node* ptr=head;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void insert_at_position(struct node **head, int data, int position)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    if (position == 1)
    {
        new_node->link = *head;
        *head = new_node;
        return;
    }

    struct node *current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->link;
    }

    if (current == NULL)
    {
        printf("Position out of bounds\n");
        free(new_node);
    }
    else
    {
        new_node->link = current->link;
        current->link = new_node;
    }
}

int print_data(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}

void delete_beginning(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->link;
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
    struct node *prev = NULL;

    if (current->link == NULL)
    {
        free(current);
        *head = NULL;
        return;
    }

    while (current->link != NULL)
    {
        prev = current;
        current = current->link;
    }

    prev->link = NULL;
    free(current);
}

void delete_pos(struct node **head,int position)
{
    struct node *current=*head;
    struct node *prev=*head;
    if(*head==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else if(position==1)
    {
        *head=current->link;
        free(current);
        current->link=NULL;
    }
    else
    {
        while(position!=1)
        {
            prev=current;
            current=current->link;
            position--;
        }
        prev->link=current->link;
        free(current);
        current=NULL;
    }
}