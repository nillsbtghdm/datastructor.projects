#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
class circulerlinkedlist {
private:
	Node* head;
	Node* tail;

public:
	circulerlinkedlist() {
		head =tail= nullptr;
	}
	Node* makiglist(){
		Node* newnode = new Node();
		newnode->next = nullptr;
		return newnode;
		}
	void insertatthefront(int data) {
		Node* newnode = new Node();
		newnode->data = data;
		if (!head) {
			newnode->next = newnode;
			head =tail= newnode;
			
		}
		else {
			newnode->next = head;
			head = newnode;
			tail->next = head;
		}
	}
	void insertattheback(int data) {
		Node* newnode = new Node();
		newnode->data = data;
		if (!tail) {
			newnode->next = newnode;;
			head = tail = newnode;
			
		}
		else {
			tail->next = newnode;
			newnode->next = head;
			tail = newnode;
		}
	}
	void insertatindex(int data, int index) {
		if (index < 0 || index > sizeoflist()) { 
			cout << "Index out of bounds" << endl;
			return;
		}
		if (index == 0) { 
			insertatthefront(data);
			return;
		}
		if (index == sizeoflist()) { 
			insertattheback(data);
			return;
		}
		Node* newnode = new Node();
		newnode->data = data;
		Node* temp = head;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	void updatenode(int data, int index) {
		Node* newnode = new Node();
		newnode->data = data;
		if (sizeoflist() == 0) {
			insertatthefront(data);
		}
		if (index<0 || index>sizeoflist()) {
			cout << "list is empty" << endl;
		}
		Node* temp = head;
		for (int i = 0; i < index; i++) {
			if (!temp) {
				cout << "index out of bound" << endl;
			}
			temp = temp->next;
		}
		temp->data = data;
	}
	int removenodeatfront() {
		if (!head) {
			cout << "list is empty" << endl;
		}
		Node* temp = head;
		int data = temp->data;
		if (sizeoflist() == 1) {
			delete temp;
			head = tail = NULL;
			return data;
		}
		else {
			head = head->next;
			tail->next = head;
		}
		delete temp;
		return data;
	}
	int remvenodeatback() {
		Node* temp = tail;
		int data = tail->data;
		if(sizeoflist()==0){
			cout << "list is empty" << endl;
		}
		if (sizeoflist() == 1) {
			delete temp;
			head = tail = NULL;
			return data;
		}
		else {
			Node* current = head;
			while (current->next != tail) {
				current = current->next;
			}
			current->next = head;
			tail = current;
			delete temp;
			return data;
		}
	}
	int removenodeatindex(int index) {
		if (index == 0) {
			return removenodeatfront();
		}
		if (index == sizeoflist()-1) {
			return removenodeatfront();
		}
		if (index > sizeoflist() || index < 0) {
			cout << "index out of bound" << endl;
		}
		
			Node* temp = head;
			for (int i = 0; i < index-1; i++) {
				temp = temp->next;
			}
			Node* todelete = temp->next;
			int data = todelete->data;
			temp->next = todelete->next;
		delete todelete;
		return data;

	}
	void printforward() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}
		Node* traverser = head;
		do {
			cout << traverser->data << "->";
			traverser = traverser->next;
		} while (traverser != head);
		cout << "End" << endl;
	}
	void invert() {
		if (!head || head->next == head) {
			return;
		}
		Node* prev = nullptr;
		Node* current = head;
		Node* nextNode;
		do {
			nextNode = current->next;  
			current->next = prev;      
			prev = current;            
			current = nextNode;        
		} while (current != head);
		head->next = prev;  
		head = prev;        
	}
	int sizeoflist() {
		int count = 0;
		Node* temp = head;
		do {
			count++;
			temp = temp->next;
		} while (temp != head);
		return count;
	}
	void concatenate(circulerlinkedlist& otherList) {
		if (!head) {
			head = otherList.head;
			tail = otherList.tail;
			if (tail) {
				tail->next = head;
			}
			return;
		}
		tail->next = otherList.head;
		tail = otherList.tail;
		tail->next = head;

	}
};
int main() {
	circulerlinkedlist cll;
	circulerlinkedlist cll2;
	cll.insertatthefront(3);
	cll.insertatthefront(4);
	cll.insertattheback(5);
	cll.insertatindex(23, 2);
	cll.removenodeatfront();
	cll.remvenodeatback();
	cll.insertatindex(8, 2);
	cll.removenodeatindex(1);
	cll.updatenode(2, 1);
	cll.printforward();
	cout << cll.sizeoflist();
	cll2.insertatthefront(5);
	cll2.insertatthefront(4);
	cll2.insertatthefront(12);
	cll.concatenate(cll2);
	cll.printforward();
	cll.invert();
	cll.printforward();
	
}