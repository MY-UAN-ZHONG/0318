#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack\n";
        cout << "Time Complexity: O(1)\n";
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
        cout << "Time Complexity: O(1)\n";
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        cout << "Time Complexity: O(1)\n";
        return arr[top];
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Stack (top -> bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "| " << arr[i] << " |\n";
        }
        cout << "-----\n";

        cout << "Time Complexity: O(n)\n";
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== Stack Menu =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Peek (Top)\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Top element: " << s.peek() << endl;
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
