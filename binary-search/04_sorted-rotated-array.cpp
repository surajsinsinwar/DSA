#include<bits/stdc++.h>
using namespace std;

int bs(int a[], int l, int h, int k) {
	int m;

	while (l <= h) {
		m = (l + h) / 2;
		if (a[m] == k) {
			return m;
		}
		else if (a[m] < k) l = m + 1;
		else h = m - 1;
	}

	return -1;
}

int pivot(int a[], int n) {
	int l = 0, h = n - 1, m;

	while (l <= h) {
		m = (l + h) / 2;
		if (a[m] <= a[n - 1]) h = m - 1;
		else {
			if (a[m + 1] <= a[n - 1]) {
				return m;
			}
			else l = m + 1;
		}
	}

	return -1;
}

int search(int a[], int n, int k) {

	if (a[0] <= a[n - 1]) {
		return bs(a, 0, n - 1, k);
	}
	else {

		int p = pivot(a, n);

		if (k >= a[0]) {
			return bs(a, 0, p, k);
		}
		else {
			return bs(a, p + 1, n - 1, k);
		}
	}

	return -1;
}


int main ()
{
	int a[] = {5, 6, 7, 1, 2, 3}, n = 6, key = 6;

	cout << search(a, n, key);

	return 0;
}