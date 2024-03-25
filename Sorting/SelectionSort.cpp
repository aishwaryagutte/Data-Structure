#include <iostream>
using namespace std;

int main()
{
	int n, pos;
	cout << "Enter size of array: ";
	cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	
	for(int i = 0;i < n;i++){
		pos = i;
		for(int j = i + 1;j < n;j++){
			if(arr[j] < arr[pos])
				pos = j;
		}
		if(i != pos){
			int tmp = arr[pos];
			arr[pos] = arr[i];
			arr[i] = tmp;
		}
	}
	
	for(int i = 0;i < n;i++){
		cout << arr[i] << "  ";
	}
	
}
