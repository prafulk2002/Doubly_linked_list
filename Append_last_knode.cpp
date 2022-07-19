#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertionathead(node* &head ,int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n;
    }
    head=n;
}

void insertattail(node* &head, int val)
{
    node* n=new node(val);
    node* temp=head;

    if(head==NULL)
    {
        insertionathead(head, val);
        return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp->next!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

node* append(node* &head, int k)
{
    node* newhead;
    node* newtail;
    node* tail=head;
    int l=length(head);
    k=k%l;
    int count=0;
    while(tail->next!=NULL)
    {
        if(count==(l-k))
        {
            newtail=tail;
        }
        if(count==(l-k+1))
        {
            newhead=tail;
        }
        tail=tail->next;
        count++;

    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;

}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    insertionathead(head, 4);
    insertionathead(head, 3);
    insertionathead(head, 2);
    insertionathead(head, 1);
    display(head);
    insertattail(head , 5);
    insertattail(head , 6);
    insertattail(head , 7);
    insertattail(head , 8);
    display(head);
    node* newhead=append(head, 3);
    display(newhead);
    return 0;

}