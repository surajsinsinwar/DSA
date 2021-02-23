#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			return i;
		}
	}

	return -1;
}

int main ()
{
	int arr[] = {0, 1, 2, 3, 4, 5}, n = 6, key = 9;

	cout << linearSearch(arr, n, key);
	cout << "\n";

	return 0;
}

