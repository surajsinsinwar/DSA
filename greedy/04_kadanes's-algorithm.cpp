#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
	int max_so_far, max_curr;
	max_so_far = max_curr = 0;

	for (int i = 0; i < n; i++)
	{
		max_curr += a[i];
		max_curr = max(0, max_curr);
		max_so_far = max(max_so_far, max_curr);
	}

	return max_so_far;
}

int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a) / sizeof(a[0]);

	cout << solve(a, n);

	return 0;
}