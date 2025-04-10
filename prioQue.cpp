#include <iostream>
using namespace std;

class PriorityQueue {
    int size;
    int capacity;
    int *values;
    int *priorities;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        values = new int[capacity];
        priorities = new int[capacity];
    }

    ~PriorityQueue() {
        delete[] values;
        delete[] priorities;
    }

    void enqueue(int value, int priority) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }

        int i;
        // (descending pr)
        for (i = size - 1; i >= 0 && priorities[i] < priority; i--) {
            values[i + 1] = values[i];
            priorities[i + 1] = priorities[i];
        }

        values[i + 1] = value;
        priorities[i + 1] = priority;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << values[0] << " (Priority: " << priorities[0] << ")" << endl;

        for (int i = 0; i < size - 1; i++) {
            values[i] = values[i + 1];
            priorities[i] = priorities[i + 1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << values[i] << "(P:" << priorities[i] << ") ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(5);
    pq.enqueue(10, 2);
    pq.enqueue(20, 5);
    pq.enqueue(30, 1);
    pq.enqueue(40, 3);
    pq.display();
    pq.dequeue();
    pq.display();

    return 0;
}
