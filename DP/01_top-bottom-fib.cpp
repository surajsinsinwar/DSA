#include<bits/stdc++.h>
using namespace std;

int a[10001];

int fib(int n)
{
	if(a[n] == -1)
	{
		int temp;
		if(n == 0 || n == 1) return n;
		temp = fib(n - 1) + fib(n - 2);
		a[n] = temp;
		return a[n];
	}
	return a[n];
}

int main()
{
	int n = 6;
	memset(a, -1, sizeof(a));

	cout << fib(n);

	return 0;
}