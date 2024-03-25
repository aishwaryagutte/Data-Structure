#include <iostream>
#define n 5
using namespace std;

class Stack{
	int top;
	int arr[n];
	public:
	Stack(){
		top = -1;
	}
	void push(int data){
		if(top == n-1){
			cout << "Stack Overflow" << endl;
		}else{
			top++;
			arr[top] = data;
		}
	}
	void pop(){
		if(top == -1)
			cout << "Stakc Underflow" << endl;
		else{
			cout << arr[top];
			top--;
		}
	}
	bool isEmpty(){
		if(top == -1)
			return true;
		else
			return false;
	}
	string isFull(){
		if(top == n-1)
			return "Stack is Full";
		else
			return "Stack is not Full";
	}
	void print(){
		cout << "Stack elements are: ";
		for(int i = top;i >= 0;i--){
			cout << arr[i] << " " ;
		}
		cout << endl;
	}
	int stackTop(){
		return arr[top];
	}
};
int main(){
	Stack stack;
	stack.pop();
	if(stack.isEmpty() == true)	
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is not empty" << endl;
	stack.push(5);
	stack.push(9);
	stack.print();
	cout << endl << stack.isFull();
	cout << endl << "Top elemsnt of stack is: "<< stack.stackTop() << endl;
	stack.push(3);
	stack.push(1);
	stack.push(0);
	stack.print();
	stack.push(12);
	stack.print();
}
