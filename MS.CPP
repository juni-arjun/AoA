#include<iostream.h>
#include<conio.h>

void merge(int a[], int start, int mid, int end){
	int n1 = mid-start+1;
	int n2 = end-mid;
	int* l = new int[n1];
	int* r = new int[n2];
	for(int i=0; i<n1; i++)
		l[i] = a[start+i];
	for(int j=0; j<n2; j++)
		r[j] = a[mid+1+j];
	int p=0, q=0, k=start;
	while(p<n1 && q<n2){
		if(l[p]<r[q]){
			a[k] = l[p];
			p++;
		}
		else{
			a[k] = r[q];
			q++;
		}
		k++;
	}
	while(p<n1){
		a[k] = l[p];
		p++;
		k++;
	}
	while(q<n2){
		a[k] = r[q];
		q++;
		k++;
	}
	delete[] l;
	delete[] r;
}

void mergeSort(int a[], int start, int end){
	if(start < end){
		int mid = start + (end-start)/2;
		mergeSort(a, start, mid);
		mergeSort(a, mid+1, end);
		merge(a, start, mid, end);
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
	mergeSort(a, 0, n-1);
	for(int j=0; j<n; j++)
		cout << a[j] << " ";
	getch();
	return 0;
}
