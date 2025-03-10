# include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value)
    {
        data=value;
        prev=nullptr;
        next=nullptr;
    }
};

class Dlinklist
{
    Node*head;
    public:
    Dlinklist()
    {
        head=nullptr;
    }
    
    void at_first(int data)
    {
      Node* newNode=new Node(data);
      newNode->next=head;
      if(head!=nullptr)
      {
          head->prev=newNode;
      }
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
    Node*temp=head;
    while(temp->next)
        {
            temp=temp->next;
        }
    temp->next=newNode;
    newNode->prev=temp;     //update prevoius Node
}
    void display()
    {
        Node* temp=head;
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
    Dlinklist obj1;
    obj1.at_first(1);
    obj1.display();
    return 0;
}
