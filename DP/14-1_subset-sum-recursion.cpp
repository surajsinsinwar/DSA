#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int sum) {
	if (n == 0)
		return sum == 0;
	return solve(a, n - 1, sum) + solve(a, n - 1, sum - a[n - 1]);

}

int main() {
	int n = 4, a[] = {10, 5, 15, 20}, sum = 15;

	cout << solve(a, n, sum);

	return 0;
}