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
        if(!head)
        {
            cout<<"this is empty"<<endl;
            return;
        }
        if(head->data==value)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
            return ;
        }
        
        Node* temp=head;
        while(temp->next && temp->next->data!=value)
        {
            temp=temp->next;
        }
        
        if(!temp->next)
        {
            cout<<"value is not found in list"<<endl;
            return ;
        }
        Node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }


    void insert(int index, int data)
    {
        if(index<0)
        {
            cout<<"invallid index"<<endl;
            return;
        }
        Node* newNode=new Node(data);
        if(index==0)
        {
            newNode->next=newNode;
            head=newNode;
        }
        Node* temp = head;
        int currentindex=0;
        while(temp->next && currentindex<index-1)
        {
            temp=temp->next;
            currentindex++;
        }
        if(!temp)
        {
            cout<<"invallid index"<<endl;
            return ;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

void deleteByIndex(int index)
{
    if(!head)
    {
        cout<<"this linklist is empty"<<endl;
        return;
    }
    if(index<0)
    {
        cout<<" this is invallid index"<<endl;
        return 0;
    }
    Node* temp=head;
    Node* prev=nullptr;
    int count=0;
    while(temp && count<index)
        {
            prev=temp;
            temp=temp->next;
            count ++;
        }
    if(!temp)
    {
        cout<<"Index out of range"<<endl;
        return;
    }
    prev->next=temp->next;
    delete temp;
}

void sum_info()
{
    int sum=0;
    Node* temp=head;
    while(temp!=NULL)
        {
            sum+=temp->data;
            temp=temp->next
        }
    return sum;
}

void count_nodes()
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    return count;
}
    void display()
    {
        if(!head)
        {
            cout<<"this is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"--->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    linklist obj1;
    obj1.at_first(1);
    obj1.append(2);
    obj1.append(3);
    obj1.append(4);
    obj1.del(4);
    obj1.insert(1,4);
    obj1.display();
    return 0;
}
