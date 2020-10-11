int solve(int a[], int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return a[0];
	return max(solve(a, n - 1), solve(a, n - 2) + a[n - 1]);
}

int main() {
	int n = 4, a[] = {10, 5, 15, 20};

	cout << solve(a, n);

	return 0;
}