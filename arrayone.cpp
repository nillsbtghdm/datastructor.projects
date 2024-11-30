#include <iostream>
using namespace std;

class QueueNill {
private:
    int front, rear, size;
    int* queue;
public:
    QueueNill(int s) {
        front = rear = -1;
        size = s;
        queue = new int[size];
    }

    void Enqueue(int object) {
        if (rear == size - 1) {
            cout << "Queue is Full";
            return;
        }
        if (front == -1)  { 
            front = 0; }
        rear++;
        queue[rear] = object;
    }

    int Dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empt";
            return 0;
        }
        front++;
        return queue[front];
    }

    int Peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty";
            return 0;
        }
        return queue[front];
    }

    bool IsEmpty() {
        return (front == -1 || front > rear);
    }

    bool IsFull() {
        return (rear == size - 1);
    }

    void ReverseQueue() {
        if (IsEmpty())
        {
            return;
        }
        int start = front, end = rear;
        while (start < end) {
            swap(queue[start], queue[end]);
            start++;
            end--;
        }
    }
};

int main() {
    QueueNill qn(6);
    qn.Enqueue(2);
    qn.Enqueue(4);
    qn.Enqueue(3);
    cout <<qn.Peek() << endl;
    qn.ReverseQueue();
    cout << qn.Peek() << endl;
    qn.Dequeue();
    cout << qn.Peek();
}