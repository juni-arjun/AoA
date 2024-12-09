#include<iostream.h>
#include<conio.h>

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

int partition(int a[], int start, int end){
	int pivot = a[end];
	int i = start-1;
	for(int j=start; j<end; j++){
		if(a[j] < pivot){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[end]);
	return i+1;
}

void quickSort(int a[], int start, int end){
	if(start < end){
		int p = partition(a, start, end);
		quickSort(a, p+1, end);
		quickSort(a, start, p-1);
	}
}


int main(){
	clrscr();
	int n, a[100];
	cout << "Enter number of elements: ";
	cin >> n;
	cout << "Enter elements: ";
	for(int i=0; i<n; i++)
		cin >> a[i];
	quickSort(a, 0, n-1);
	for(int j=0; j<n; j++)
		cout << a[j] << " ";
	getch();
	return 0;
}
