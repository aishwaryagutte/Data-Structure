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
	int l = 0, r = size, mid = (l+r)/2;
	while(l <= r){
		if(searchValue < mid){
			r--;
		}
		if(searchValue > mid){
			l++;
		}
		if(arr[mid] == searchValue)
			break;
	}
	
	if(l > r)
		cout << "\nElement not found";
	else
		cout << "\nElement found";
}

