#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int key) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] <= key) count++;
	}

	return count;
}

int kthSmallest(int a[], int n, int k) {

	int start = a[0], end = a[0], m, count;

	for (int i = 0; i < n; i++) {
		start = min(start, a[i]);
		end = max(end, a[i]);
	}

	while (start <= end) {
		m = (start + end) / 2;
		count = solve(a, n, m);

		if (count < k) start = m + 1;
		else {
			count = solve(a, n, m - 1);

			if (count < k) return m;
			else end = m - 1;
		}
	}

	return 0;
}

int main() {

	int a[] = {7 , 8, 7, 4, 3, 9}, n = 6;

	cout << kthSmallest(a, n, 3);

	return 0;
}