#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear >= MAX - 1) {
            cout << "Queue Overflow!\n";
            return;
        }
        arr[++rear] = x;
        cout << x << " added to queue\n";
        cout << "Time Complexity: O(1)\n";
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " removed from queue\n";
        front++;
        cout << "Time Complexity: O(1)\n";
    }

    int getFront() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return -1;
        }
        cout << "Time Complexity: O(1)\n";
        return arr[front];
    }

    void display() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue (front -> rear): ";
        for (int i = front; i <= rear; i++) {
            cout << "[" << arr[i] << "] ";
        }
        cout << endl;

        cout << "Time Complexity: O(n)\n"; // 因為要走訪全部元素
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n===== Queue Menu =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Front\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Front element: " << q.getFront() << endl;
            break;

        case 0:
            cout << "Bye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
