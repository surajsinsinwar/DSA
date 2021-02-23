#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key) {

	int start = 0, end = n - 1, mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return -1;
}

int main ()
{
	int arr[] = {0, 1, 2, 3, 4, 5}, n = 6, key = 5;

	cout << binarySearch(arr, n, key);

	return 0;
}