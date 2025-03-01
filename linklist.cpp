#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value)
    {
        data=value;
        next=nullptr;
    }
};

class linklist{
    Node* head;
    public:
    linklist()
    {
        head=nullptr;
    }
    
    void at_first(int data)
    {
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }
    
    void append(int data)
    {
        Node* newNode=new Node(data);
        if(!head)
        {
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"----->";
            temp=temp->next;
        }
        cout<<"Null"<<endl;
    }
};
int main()
{
    linklist obj1;
    obj1.at_first(1);
    obj1.append(23);
    obj1.append(45);
    obj1.append(54);
    obj1.display();
    return 0;
}
