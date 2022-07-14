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

void deleteathead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
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
    deleteathead(head);
    display(head);
    return 0;

}