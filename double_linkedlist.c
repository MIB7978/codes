#include <stdio.h>
#include<stdlib.h>  

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

// insert at beginning
Node* insert_at_end(Node *head,int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
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
        temp->prev=p;
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
        head->prev=temp;
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
        if(p==head){
            p->prev=temp;
            temp->next=p;
            head=temp;
        }
        else{
            temp->next=p->next;
            temp->prev=p;
            p->next->prev=temp;
            p->next=temp;
        }    
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
        Node *temp;
        while(p && p->data!=data){
        temp = p;
        p=p->next;
        
            
        }
        if(p==NULL)printf("given node is not found");
        else
        {
            if(p==head)
            {
                head=head->next;
                head->prev=NULL;
                p->next=NULL;
            }
            else
            {
                temp->next=p->next;
                if(p->next!=NULL)p->next->prev=temp;
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
    while(p->next)
    {
        p=p->next;
    }
    while(p)
    {
        printf("%d-> ",p->data);
        p=p->prev;
    }
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
	printf("\n");
	head = Delete(head,22);
    // head = reverse(head);
	traverse(head);
	return 0;
}
