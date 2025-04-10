#include <iostream>
using namespace std;

class circularQue {
    int size;
    int *arr;
    int front;
    int rear;
public:
    circularQue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    ~circularQue() {
        delete[] arr;
    }

    void enque(int data) {
        if ((rear + 1) % size == front) {
            cout << "This queue is full" << endl;
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;     // index dixa tail ko
        }
        arr[rear] = data;
    }

    void deque() {
        if (front == -1) {
            cout << "This queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    circularQue cc(3);
    cc.enque(1);
    cc.enque(2);
    cc.deque();
    cc.enque(3);
    cc.enque(4);
    cc.display();

    return 0;
}
