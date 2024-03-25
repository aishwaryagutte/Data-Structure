#include <iostream>
using namespace std;

class Node{
	int data;
	Node *next;
	public:
	Node(){
		data = 0;
		next = NULL;	
	}
	Node(int d){
		data = d;
		next = NULL;
	}
	int getData(){
		return data;
	}
	Node * getNext(){
		return next;
	}
	void setNext(Node *p){
		next = p;
	}
};
class Stack:public Node{
	Node * top;
	public:
	Stack(){
		top = NULL;
	}
	void push(int d){
		Node * newNode = new Node(d);
		if(newNode == NULL){
			cout << "\nStack Overflow";
			return;
		}
		newNode -> setNext(top);
		top = newNode;
	}
	void pop(){
		if(top == NULL){
			cout << "\nStack Underflow";
			return;
		}
		top = top -> getNext();
	}
	void print(){
		Node * tmp = top;
		if(tmp == NULL){
			cout << "\nStack Underflow";
			return;
		}
		cout << endl;
		while(tmp -> getNext() != NULL){
			cout << tmp -> getData() << " ";
			tmp = tmp -> getNext();
		}
		cout << tmp -> getData() << " ";
	}
	bool isEmpty(){
		return top == NULL;
	}
	int peek(){
		return top -> getData();
	}
};
int main(){
	Stack stk;
	if(stk.isEmpty() == true)
		cout << "\nStack is Empty";
	else
		cout << "\nStack is not empty";
	stk.push(7);
	stk.push(9);
	stk.push(10);
	stk.print();
	stk.pop();
	stk.print();
	cout << endl << stk.peek();
}
