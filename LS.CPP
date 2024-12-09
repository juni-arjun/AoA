#include<iostream.h>
#include<conio.h>

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
	int ans = -1;
	for(int i=0; i<5; i++){
		if(a[i]==key) {
			ans = i+1;
			break;
		}
	}
	if(ans==-1){
		cout << key << " is not present in the array." << endl;
	}
	else{
		cout << key << " is present at index " << ans << " of array." << endl;
	}
	getch();
	return 0;
}
