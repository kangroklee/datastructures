// w/ recursion!!
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

void Print(Node * p) 
{
    if(p==NULL) //exit condition
    {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    Print(p->next); //recursive call
}

void ReversePrint(Node * p) 
{
    if(p==NULL) //exit condition
    {
        printf("\n");
        return;
    }
    ReversePrint(p->next); //recursive call
    printf("%d ", p->data);
}

Node *Insert(Node *head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp; // Insert node at end
    }
    return head;
}

int main(void)
{
    Node *head = NULL; // local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    printf("\n");
    PrintR(head);
    return 0;
}
