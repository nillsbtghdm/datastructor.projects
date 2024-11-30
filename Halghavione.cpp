#include <iostream>
using namespace std;

class QueueNillhalgavei {
private:
    int front, rear, size;
    int* queue;
public:
    QueueNillhalgavei(int s) {
        front = rear = -1;
        size = s;
        queue = new int[s];
    }

    void Enqueue(int object) {
        if ((rear + 1) % size == front) {
            cout << "Queue is Full";
            return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = object;
    }

    int Dequeue() {
        if (front == -1) {
            cout << "Queue is Empty";
            return 0;
        }
        int data = queue[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return data;
    }

    int Peek() {
        if (front == -1) {
            cout << "Queue is Empty";
            return 0;
        }
        return queue[front];
    }

    bool IsEmpty() {
        return (front == -1);
    }

    bool IsFull() {
        return ((rear + 1) % size == front);
    }

    void ReverseQueue() {
        if (IsEmpty())
        {
            return;
        }
        int start = front, end = rear;
        while (start != end) {
            swap(queue[start], queue[end]);
            start = (start + 1) % size;
            if (start == end)
            {
                break;
            }
            end = (end - 1 + size) % size;
        }
    }
};
int main() {
    QueueNillhalgavei qn(4);
    qn.Enqueue(6);
    qn.Enqueue(8);
    cout << qn.Peek() << endl;
    qn.Dequeue();
    cout << qn.Peek() << endl;
    qn.Enqueue(9);
    qn.ReverseQueue();
    cout << qn.Peek();
}
