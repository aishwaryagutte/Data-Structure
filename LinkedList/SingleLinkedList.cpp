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
		this -> next = p;
	}
	void setData(int data){
		this -> data = data;
	}
};
class SingleLL:public Node{
	Node * head = NULL;
	public:
	
	void insertAtBegin(int data){
		if(head == NULL){
			head = new Node(data);
			head -> setNext(NULL);
		}else{
			Node * newNode = new Node(data);
			newNode -> setNext(head);
			head = newNode;
		}
	}
	
	void insertAtEnd(int data){
		if(head == NULL){
			head = new Node(data);
			head -> setNext(NULL);
		}else{
			Node * tmp = head;
			while((tmp -> getNext()) != NULL){
				tmp = tmp -> getNext();
			}
			Node * newNode= new Node(data);
			tmp -> setNext(newNode);
		}
	}
	
	void printList(){
		Node * tmp = head;
		while((tmp -> getNext()) != NULL){
			cout<< tmp -> getData()<<" ";
			tmp = tmp -> getNext();
		}
		cout<<tmp -> getData();
	}
	
	void insertAtIndex(int index, int data){
		if(head == NULL){
			if(index > 0){
				cout<<"\n Index is not valid";
				return;
			}
			head = new Node(data);
			head -> setNext(NULL);
		}else{
			int size = 1;
			Node * tmp = head;
			Node * tp = head;
			while(tmp -> getNext() != NULL && size <= index){
				if(size == index){
					Node * newNode = new Node(data);
					newNode -> setNext(tmp);
					tp -> setNext(newNode);
					return;
				}
				size++;
				tp = tmp;
				tmp = tmp -> getNext();
			}
		}
	}
	
	void removeFromEnd(){
		Node * tmp = head;
		Node * tp = NULL;
		while(tmp -> getNext() != NULL){
			tp = tmp;
			tmp = tmp -> getNext();
		}
		tp -> setNext(NULL);
	}
	
	void removeFromStart(){
		Node * tmp = head;
		head = tmp->getNext();
	}
	
	int length(){
		int length = 0;
		Node * tmp = head;
		while(tmp -> getNext() != NULL){
			tmp = tmp ->getNext();
			length++;
		}
		return length+1;
	}
	
	int mid(){
		int mid = 0;
		Node * tmp = head;
		Node * tmp2 = head;
		while(tmp2 -> getNext() != NULL || tmp2 -> getNext() -> getNext() != NULL){
			if(tmp2 -> getNext() == NULL){
				//tmp = tmp -> getNext();
				cout<<"---------------"<<tmp->getData();
				return tmp -> getData();
			}
			if(tmp2 -> getNext() -> getNext() == NULL){
			tmp = tmp -> getNext();
				return tmp -> getData();
			}
			tmp2 = tmp2 -> getNext();
			tmp2 = tmp2 -> getNext();
			tmp = tmp -> getNext();
			
			mid += 2;
		}
		return mid;
	}
};
int main(){
	SingleLL list;
	list.insertAtEnd(10);
	list.insertAtEnd(20);
	list.insertAtEnd(30);
	list.insertAtEnd(40);
	list.insertAtEnd(50);
	list.insertAtBegin(60);
	list.insertAtBegin(70);
	list.insertAtIndex(2,90);
	list.insertAtIndex(3,100);
	list.printList();
	list.removeFromStart();
	cout << endl;
	list.printList();
	list.removeFromEnd();
	cout << endl;
	list.printList();
	cout << "\nLength of list is: "<< list.length();
	cout << "\nMid of the list is: "<< list.mid();
	return 0;
}
