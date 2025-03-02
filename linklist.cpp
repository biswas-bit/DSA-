# include<iostream>
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

class linklist
{
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
    void del(int value)
    {
        if(!head){
            cout<<"empty list"<<endl;
            return;
        }
        if(head->data==value)
        {
            Node* temp= head;
            head=head->next;
            delete temp;
            return;
        }
        
        Node*temp=head;
        while(temp->next && temp->next->data!=value)
        {
            temp=temp->next;
        }
        if(!temp->next){
            cout<<"this value doesnot exists"<<endl;
            return;
        }
        
        Node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
    
    void display()
    {
        if(!head)
        {
            cout<<"this is empty list"<<endl;
            return;
        }
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    linklist obj1;
    obj1.at_first(12);
    obj1.append(23);
    obj1.append(45);
    obj1.append(67);
    obj1.del(45);
    obj1.display();
    return 0;
}
