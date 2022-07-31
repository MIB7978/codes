#include <stdio.h>
#include<stdlib.h>  

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

// insert at beginning
Node* insert_at_end(Node *head,int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node *p=head;
        while(p->next)
        p=p->next;
        p->next=temp;
    }
    return head;
}

// insert at beginning 
Node* insert_at_beginning(Node * head,int x)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}

// insert node after a node
Node* insert_after_given_node(Node * head,int data,int item)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next=NULL;
    if(head==NULL)
    printf("list is empty");
    else
    {
        Node *p=head;
        while(p && p->data!=data){
        p=p->next;
        }
        if(!p)
        printf("given node not found");
        else{
        temp->next=p->next;
        p->next=temp;
            
        }
    }
    return head;
}


//delete a node 
Node * Delete(Node *head,int data)
{
    Node *p=head;
    if(p==NULL)printf("list is empty");
    else
    {
        Node *prev;
        while(p && p->data!=data){
        prev = p;
        p=p->next;
        
            
        }
        if(p==NULL)printf("given node is not found");
        else
        {
            if(p==head)
            {
                head=p->next;
                p->next=NULL;
            }
            else
            {
                prev->next=p->next;
                p->next=NULL;
            }
            free(p);
        }
    }
    return head;
}

Node* reverse(Node * head)
{
    Node *p=head;
    Node *curr,*prev;
    prev = NULL;
    curr=p;
    while(p)
    {
        p=p->next;
        curr->next=prev;
        prev=curr;
        curr=p;
    }
    head=prev;
    return head;
}


//traverse the list
void  traverse(Node * head)
{
    Node * p = head;
    while(p)
    {
        printf("%d->",p->data);
        p=p->next;
    }
}


int main() {
	Node *head=NULL;
	head = insert_at_end(head,10);
	head = insert_at_end(head,20);
	head= insert_at_beginning(head,5);
	head = insert_after_given_node(head,10,11);
	head = insert_after_given_node(head,11,12);
	head = insert_at_end(head,22);
	traverse(head);
	printf("\n after revere");
// 	head = Delete(head,5);
    head = reverse(head);
	traverse(head);
	return 0;
}
