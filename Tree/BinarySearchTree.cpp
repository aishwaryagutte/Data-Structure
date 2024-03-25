#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node * left;
	Node * right;
	
	Node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
	Node * createNode(int val){
		Node * newNode = new Node();
		newNode -> data = val;
		newNode -> left = newNode -> right= NULL;
		return newNode;
	}
};

class BST: public Node{
	public:
	Node * root = NULL;
	
	void insert(int val){
		if(root == NULL){
			root = createNode(val);
		}else{
			Node * newNode = createNode(val);
			Node * tmp = root;
			
			while(tmp != NULL){
				
				if(val < tmp->data){
					if(tmp -> left == NULL){
						tmp->left = newNode;
						return;
					}	
					tmp =  tmp -> left;
				}
			
				if(val > tmp->data){
					if(tmp -> right == NULL){
						tmp->right = newNode;
						return;
					}
					tmp =  tmp -> right;
				}
			}
		}
	}
	
	void preorder(Node* root){
    		if (root != NULL) {
    			cout << root->data << " ";
        		inorder(root->left);
        		inorder(root->right);
    		}
	}
	
	void inorder(Node* root){
    		if (root != NULL) {
        		inorder(root->left);
        		cout << root->data << " ";
        		inorder(root->right);
    		}
	}
	
	void postorder(Node* root){
    		if (root != NULL) {
        		inorder(root->left);
        		inorder(root->right);
        		cout << root->data << " ";
    		}
	}
	
	bool search(int val){
		Node * tmp = root;
		
		while(tmp != NULL){

			if(val == tmp -> data){
				return true;
			}
				
			if(val < tmp -> data){
				if(val == tmp -> data)
					return true;
				tmp = tmp -> left;
			}else if(val > tmp -> data){
				if(val == tmp ->data)
					return true;
				tmp = tmp -> right;
			}
		}
		return false;
	}
	
	int deleteVal(int val){
	
	}
	
};

int main(){
	BST *t = new BST();
	t -> insert(90);
	t->insert(30);
	t->insert(100);
	t->insert(10);
	t->insert(110);
	
	cout << "\nPreOrder traversal is:  ";
	t->preorder(t->root);
	cout << "\nInOrder traversal is:   ";
	t->inorder(t->root);
	cout << "\nPostOrder traversal is: ";
	t->postorder(t->root);
	
	int sNo;
	cout << "\nEnter element to search: ";
	cin >> sNo;
	if(t -> search(sNo) == true)
		cout<< "The number "<< sNo << " is present in given binary search tree...";
	else
		cout<< "The number "<< sNo << " is not present in given binary search tree...";
		
	int dNo;
	cout << "\nEnter element to delete: ";
	cin >> dNo;
	t -> deleteVal(dNo);
}
