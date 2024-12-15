#include <iostream>
using namespace std;

class stackn {
private:
    int top, size;
    int* stack;
public:
    stackn(int n) {
        top = -1;
        size = n;
        stack = new int[n];
    }

    void push(int item) {
        if (top >= size - 1) {
            cout << "Stack overflow" << endl;
        }
        else {
            stack[++top] = item;
        }
    }

    int pop() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else {
            return stack[top--];
        }
    }

    bool isempty() {
        return top == -1;
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }


};

int main() {
    stackn sn(4);
    sn.push(4);
    sn.push(10);
    sn.push(53);
    sn.display();
    sn.pop();
    sn.display();

}