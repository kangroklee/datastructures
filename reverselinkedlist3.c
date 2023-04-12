// 230412 w/ recursion, head is global var.
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node* head = NULL;
void Reverse(Node*p)
{
    if(p->next==NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    /*these 3 lines will execute 'after' recursive call*/
    Node* q = p->next; //could write p->next->next=p
    q->next = p;
    p-> next= NULL;
}

void Insert(int data)
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
}

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

int main(void)
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print(head);
    Reverse(head);
    Print(head);
    return 0;
}
