# include<iostream>
using namespace std;

// create Node
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

// list
class list{
    Node* head;
    Node* tail;
    public:
    list(){
        head=NULL;
        tail=NULL;
    }
    //at first
    void push_first(int data)
    {
        Node* newNode=new Node(data);
        if(!head)
        {
            head=tail=newNode;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    // at last
    void push_back(int data){
        Node* newNode=new Node(data);
         if(!head)
        {
            head=tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    // delete first element
    void pop_front()
    {
        if(!head)
        {
            cout<<"this list is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    //delete last element
    void pop_back()
    {
        if(!head)
        {
            cout<<"this list is empty"<<endl;
            return ;
        }
        Node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
      delete tail;
      tail=temp;
      tail->next=NULL;
    }
 // insert
    void insert(int value, int pos)
    {
        Node* newNode=new Node(value);
        if(pos<0)
        {
            cout<<"invallid position"<<endl;
            return;
        }
        
        if(pos==0)
        {
            push_first(value);
        }
        
        Node* temp=head;
        for(int i=0;i<pos-1;i++)
        {
            if(temp==NULL)
            {
                cout<<"invalid pos\n";
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    
    void print(){
        if(!head)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<"NUll"<<endl;
    }
};
int main()
{
    list ll;
    ll.push_first(1);
    ll.push_first(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.print();
    ll.pop_front();
    ll.print();
    ll.pop_back();
    ll.print();
    ll.insert(2,1);
    ll.print();
    return 0;
}
