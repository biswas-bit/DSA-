#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {  // eta Node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {  // euta Node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void display_forward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void display_backward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.push_front(10);
    dll.push_front(20);
    dll.push_back(5);
    dll.display_forward();   // 20 <-> 10 <-> 5
    dll.display_backward();  // 5 <-> 10 <-> 20

    dll.pop_front();         // Removes 20
    dll.pop_back();          // Removes 5

    dll.display_forward();   // 10
    dll.display_backward();  // 10

    return 0;
}
