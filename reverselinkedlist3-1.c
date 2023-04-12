// 230402 w/ recursion, head is local var
//[RESOLVED]*****not working, wtf happens when return head in Reverse()??*****
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

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

Node* Reverse(Node*p, Node*head) //where head is not a global var; all about passing the head in recursive function calls.
{
    if(p->next==NULL)
    {
        head = p;
        return head;
    }
    head = Reverse(p->next, head); //highlight!!
    /*these 3 lines will execute 'after' recursive call*/
    Node* q = p->next; //could write p->next->next=p
    q->next = p;
    p-> next= NULL;

    return head; 
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
    Node *head = NULL; // local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    head = Reverse(head, head);
    Print(head);
    return 0;
}
