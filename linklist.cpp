# include<iostream>
using namespace std;

struct Node{                                    // create head
    int data;                                   // |--------|----------|
    Node* next;                                 // |  data  | next     |   
    Node(int value)                             // |--------|----------|
    {
        data= value;
        next=nullptr;
    }
};

class linklist{
    Node* head;
    linklist()
    {
        head=nullptr;
    }
    void insert_at_first(int data)
    {
        new* newNode=new Node(data);    // make new Node
        newNode->next=head;             // link with the next node hold the address of thas
        head=newNode;                   
    }
    
    void append(int data)
    {
        new* newNode=new Node(data);
        if(!head)
        {
            newNode=head;
            return;
        }
        new* temp=head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    
   
};
