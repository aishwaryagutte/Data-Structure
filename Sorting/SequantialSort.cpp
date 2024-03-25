#include <iostream>
using namespace std;

int main(){
	int size,searchValue;
	cout << "Enter Size of array: ";
	cin >> size;
	cout << "Enter Search value: : ";
	cin >> searchValue;
	int arr[size];
	for(int i = 0;i < size;i++){
		cin >> arr[i];
	}
	int i = 0;
	for(i = 0;i < size;i++){
		if(arr[i] == searchValue)
			break;
	}
	if(i == size)	
		cout << "\n Element Not found...";
	else
		cout << "\n Element found...";
}
