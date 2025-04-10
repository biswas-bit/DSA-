#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node *head;
    Node *tail;

public:
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_first(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
            tail->next = head;  // connect tail to head(circular banauna lai)
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;  
        }
    }

    void push_last(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;  
        }
    }

    void pop_first() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularLinkedList cl;
    cl.push_first(10);
    cl.push_first(20);
    cl.push_last(5);

    cl.display();  
    cl.pop_first();
    cl.display();  
    return 0;
}
