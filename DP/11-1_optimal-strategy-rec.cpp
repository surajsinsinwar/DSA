#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int i, int j) {
	if (i + 1 == j)
		return max(a[i], a[j]);
	int m = min(solve(a, i + 2, j), solve(a, i + 1, j - 1)) + a[i];
	int n = min(solve(a, i, j - 2), solve(a, i + 1, j - 1)) + a[j];
	return max(m, n);
}

int main() {
	int a[] = {20, 5, 4, 6};
	int n = sizeof(a) / sizeof(a[0]);

	cout << solve(a, 0, n - 1);

	return 0;
}