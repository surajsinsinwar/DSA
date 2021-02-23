#include<bits/stdc++.h>
using namespace std;

int firstOcc(int a[], int n, int key) {

	int l = 0, h = n - 1, m;

	while (l <= h) {
		m = (l + h) / 2;

		if (a[m] == key) {
			if (m == 0 || a[m - 1] != a[m]) {
				return m;
			}
			else h = m - 1;
		}
		else if (a[m] > key) {
			h = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return -1;
}

int main ()
{
	int a[] = {0, 2, 2, 3, 4, 4}, n = 6, key = 4;

	cout << firstOcc(a, n, key);

	return 0;
}