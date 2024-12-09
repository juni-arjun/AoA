#include<iostream.h>
#include<conio.h>

int binarySearchRecursive(int a[], int start, int end, int key){
	if(start > end){
		return -1;
	}
	int mid = start + (end-start)/2;
	if(a[mid]==key){
		return mid;
	}
	if(a[mid]<key){
		return binarySearchRecursive(a, mid+1, end, key);
	}
	return binarySearchRecursive(a, start, mid-1, key);
}

int binarySearch(int a[], int n, int key){
	int start = 0, end = n;
	while(start <= end){
		int mid = start + (end-start)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return -1;
}
int main(){
	clrscr();
	int n;
	cout << "Enter number of elements in the array: ";
	cin >> n;
	int a[100];
	cout << "Enter elements of the array: ";
	for(int j=0; j<n; j++){
		cin >> a[j];
	}
	int key;
	cout << "Enter elemet to be searched: ";
	cin >> key;
//	int ans = binarySearch(a, n, key);
	int ans = binarySearchRecursive(a, 0, n-1, key);
	if(ans==-1){
		cout << key << " is not present in the array." << endl;
	}
	else{
		cout << key << " is present at index " << ans << " of array." << endl;
	}
	getch();
	return 0;
}