#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* head;
void Reverse()
{
    Node * current, * prev, * next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        /*real action here*/
        next = current->next;
        current->next = prev;
        /*simply for going to next node*/
        prev = current;
        current = next;
    } 
    head = prev;
}

void Insert(int data, int n)
{
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = data;
    temp1->next = NULL;
    if(n==1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for(int i=0;i<n-2;i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Print()
{
    Node* temp = head;
    printf("List is: ");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(void)
{
    Insert(2,1);
    Insert(4,2);
    Insert(6,3);
    Insert(8,4);
    Print();
    Reverse();
    Print();
    return 0;
}