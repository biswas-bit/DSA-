#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Solution {
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* l3 = new Node(0); // Dummy node
        int carry = 0;
        Node* head = l3;

        // Sum corresponding nodes while both lists exist
        while (l1 && l2) {
            int value = l1->data + l2->data + carry;
            carry = value / 10;
            l3->next = new Node(value % 10);
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // Process remaining nodes in l1
        while (l1) {
            int value = l1->data + carry;
            carry = value / 10;
            l3->next = new Node(value % 10);
            l3 = l3->next;
            l1 = l1->next;
        }

        // Process remaining nodes in l2
        while (l2) {
            int value = l2->data + carry;
            carry = value / 10;
            l3->next = new Node(value % 10);
            l3 = l3->next;
            l2 = l2->next;
        }

        // If carry remains, create a new node
        if (carry) {
            l3->next = new Node(carry);
        }

        return head->next; 
    }
};

// Helper function to print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


Node* createList(int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3}; // Represents number 342
    int arr2[] = {5, 6, 4}; // Represents number 465

    Node* l1 = createList(arr1, 3);
    Node* l2 = createList(arr2, 3);

    Solution sol;
    Node* result = sol.addTwoNumbers(l1, l2);

    printList(result); // Expected output: 7 -> 0 -> 8 -> NULL (342 + 465 = 807)

    return 0;
}
