#include <iostream>
using namespace std;

class que {
    int size;
    int *arr;
    int front;
    int rear;

public:
    que(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    ~que() {
        delete[] arr;
    }

    void push(int data) {
        if (rear == size - 1) {
            cout << "This queue is full" << endl;
            return;
        }
        if (front == -1) { 
            front = 0;
        }
        arr[++rear] = data;
    }

    void pop() {
        if (front == -1 || front > rear) {
            cout << "This queue is empty" << endl;
            return;
        }
        cout << "Popped: " << arr[front++] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "This queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    que q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.pop();
    q.display();
    return 0;
}
