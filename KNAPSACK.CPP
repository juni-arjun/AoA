#include<iostream.h>
#include<conio.h>

int max(int a, int b){
	return a>b? a: b;
}

int kSackRec(int W, int wt[], int val[], int index, int** memo) {
    if (index < 0)
	return 0;

    if (memo[index][W] != -1)
	return memo[index][W];

    if (wt[index] > W) {
	memo[index][W] = kSackRec(W, wt, val, index - 1, memo);
    } else {
	memo[index][W] = max(val[index] +
		kSackRec(W - wt[index], wt, val, index - 1, memo),
		kSackRec(W, wt, val, index - 1, memo));
    }

    return memo[index][W];
}

int knapSack(int W, int wt[], int val[], int n) {
    int** memo = new int*[n];
    for (int i = 0; i < n; i++) {
	memo[i] = new int[W + 1];
	for (int j = 0; j <= W; j++) {
	    memo[i][j] = -1;
	}
    }

    int result = kSackRec(W, wt, val, n - 1, memo);

    for (int k = 0; k < n; k++) {
	delete[] memo[i];
    }
    delete[] memo;

    return result;
}


int main(){
	clrscr();
	int n, profit[100], weight[100], W, i;
	cout << "Enter number of items: ";
	cin >> n;
	cout << "Enter profit items: ";
	for(i=0; i<n; i++)
		cin >> profit[i];
	cout << "Enter weight of items: ";
	for(i=0; i<n; i++)
		cin >> weight[i];
	cout << "Enter maximum weight capacity: ";
	cin >> W;
	cout << knapSack(W, weight, profit, n) << endl;
	getch();
	return 0;
}
