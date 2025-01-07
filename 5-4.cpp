#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};

class singlelinkedlist {
private:
    Node* head;

public:
    singlelinkedlist() {
        head = nullptr;
    }

    void makingthelist() {
        head = new Node();
        Node* second = new Node();
        Node* third = new Node();

        head->data = 1;
        second->data = 2;
        third->data = 3;

        head->next = second;
        second->next = third;
        third->next = nullptr;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "End" << endl;
    }
    void insertatthefront(int data) {
        Node* newnode = new Node();
        newnode->data = data;
        newnode->next = head;
        head = newnode;
    }
    void insertattheback(int data) {
        Node* newnode = new Node();
        newnode->data = data;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = newnode;
            return;
        }

        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newnode;
    }
    void insertAtIndex(int data, int index) {
        if (index == 0) {
            insertatthefront(data);
            return;
        }

        Node* newnode = new Node();
        newnode->data = data;

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (!temp) {
                throw out_of_range("Index out of bounds");
            }
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
    int removenodeatindex(int index) {
        if (index == 0) {
            if (!head) throw out_of_range("Index out of bounds");

            Node* temp = head;
            int data = head->data;
            head = head->next;
            delete temp;
            return data;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (!temp || !temp->next) {
                throw out_of_range("Index out of bounds");
            }
            temp = temp->next;
        }

        Node* removenode = temp->next;
        temp->next = removenode->next;
        int data = removenode->data;
        delete removenode;
        return data;
    }
    int removedataatthefront() {
        if (!head) {
            cout << "index out of the bound" << endl;
        }
        Node* temp = head;
        int data = head->data;
        head = head->next;
        delete temp;
        return data;

    }
    int removeattheback() {
        if (!head) {
            cout << "index out of the bound" << endl;
        }
        if (!head->next) {
            int data = head->data;
            delete head;
            head = NULL;
            return data;
        }
        Node* prev = NULL;
        Node* temp = head;

        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        int data = temp->data;
        delete temp;
        prev->next = NULL;
        return data;
    }
    int sizeofthelist() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        int sizeofthelist = count;
        return sizeofthelist;
    }
    void concatenate(singlelinkedlist& otherlists) {
        if (!head) {
            head = otherlists.head;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = otherlists.head;
    }
    void invert() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};
class Arraywithlinkedlist {
private:
    singlelinkedlist s;
public:
    void insert(int index, int value) {
        s.insertAtIndex(value,index);
    }

    int delete_by_index(int index) {
        s.removenodeatindex(index);
    }

    void display() {
        s.display();
    }

    void append(int value) {
        s.insertattheback(value);
    }

    void reverse() {
        s.invert();
    }
    void size() {
        s.sizeofthelist();
    }
};
int main() {
    Arraywithlinkedlist al;
    al.insert(0, 2);
    al.insert(1, 2);
    al.append(5);
    al.display();
    al.reverse();
    al.display();
}