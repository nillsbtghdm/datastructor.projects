#include <iostream>
using namespace std;

class stackn {
private:
    int top, n;
    int* stack;
public:
    stackn(int size) {
        top = -1;
        n = size;
        stack = new int[size];
    }
    void push(int item) {
        if (top >= n - 1) {
            cout << "stack overflow" << endl;
        }
        else {
            stack[++top] = item;
        }
    }
    int pop() {
        if (top == -1) {
            cout << "stack underflow" << endl;
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
       for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        
    }
    int gettop() const {
        return top; 
    } 
    int getstack(int index) const {
        return stack[index]; 
    }
};

class queuetackni {
private:
    stackn s1, s2;
public:
    queuetackni(int size) : s1(size), s2(size) {}
    void enqueue(int item) {
        s1.push(item);
    }
    int dequeue() { 
        if (s1.isempty()) {
            cout << "queue is emty" << endl; 
            return -1;
        } 
        else {
            s2.push(s1.pop()); 
            return s2.pop();
        } }
    void display() {
            for (int i = s2.gettop(); i >= 0; i--) {
                cout << s2.getstack(i) << " ";
            }
            for (int i = 0; i <= s1.gettop(); i++) {
                cout << s1.getstack(i) << " ";
            }
            cout << endl;
        }
    
};

int main() {
    queuetackni qi(4);
    qi.enqueue(4);
    qi.enqueue(6);
    qi.enqueue(25);
    qi.enqueue(74);
    qi.display();
    cout << "dequeued: " << qi.dequeue() << endl;
    qi.display();
}
