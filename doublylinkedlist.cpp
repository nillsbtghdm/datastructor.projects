#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* previous;
};

class doublylinkedlist {
private:
    Node* head;
    Node* tail;

public:
    doublylinkedlist() : head(nullptr), tail(nullptr) {}

    void insertatthefront(int data) {
        Node* newnode = new Node();
        newnode->data = data;
        newnode->next = head;
        newnode->previous = nullptr;
        if (!head) {
            head = tail = newnode;
        }
        else {
            head->previous = newnode;
            head = newnode;
        }
    }
    void insertattheback(int data) {
        Node* newnode = new Node();
        newnode->data = data;
        newnode->next = nullptr;
        newnode->previous = tail;
        if (!tail) {
            head = tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    void insertatindex(int data, int index) {
        if (index < 0 || index > sizofthelist()) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0) {
            insertatthefront(data);
            return;
        }
        if(index==sizofthelist()){
            insertattheback(data);
            return;
        }
        Node* newnode = new Node();
        newnode->data = data;
        Node* temp = head;
        for (int i = 0; i < index-1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->previous = temp;
        temp->next = newnode;

    }
    void updatenode(int data, int index) {
        Node* temp = head;
        if (!temp) {
            cout << "index ou of the bound" << endl;
        }
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = data;
    }
    int sizofthelist(){
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    int removenodeatfront() {
        if (sizofthelist() == 0) {
            cout << "List is empty!";
            return -1;
        }
        Node* temp = head;
        if (sizofthelist() == 1) {
            int data = temp->data;
            delete temp;
            head = tail = NULL;
            return data;
        }
        int data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }
    int removenodeatback() {
        if (sizofthelist() == 0) {
            cout << "List is empty!" << endl;
            return -1;
        }
        Node* temp = tail;
        int data = temp->data;
        if (sizofthelist() == 1) {
            delete temp;
            head = tail = nullptr;
            return data;
        }
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
        return data;
    }
    void concatenate(doublylinkedlist&otherlists){
        if (!head) {
            head = otherlists.head;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = otherlists.head;
    }
    void printforward() {
        Node* traverser = head;
        while (traverser) {
            cout << traverser->data << "->";
            traverser = traverser->next;
        }
        cout << "End" << endl;
    }
    void printbackward() {
        Node* traverser = tail;
        while (traverser) {
            cout << traverser->data << "->";
            traverser = traverser->previous;
        }
        cout << "End" << endl;
    }

};

int main() {
    doublylinkedlist dll;
    dll.insertatthefront(2);
    dll.insertattheback(5);
    dll.insertatthefront(3);
    dll.insertatindex(8, 3);
    dll.updatenode(12, 2);
    dll.printforward();
    dll.printbackward();
    cout << dll.sizofthelist() << endl;
    dll.removenodeatback();
    dll.printforward();
    doublylinkedlist dll2;
   dll2.insertattheback(4);
   dll2.insertattheback(5);
   dll2.insertattheback(6);
   dll.concatenate(dll2);
   dll.printforward();
}
