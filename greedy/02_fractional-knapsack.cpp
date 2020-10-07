#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	double r1 = (double)a.first / a.second;
	double r2 = (double)b.first / b.second;

	return r1 > r2;
}

int solve(pair<int, int> a[], int n, int w)
{
	sort(a, a + n, cmp);
	double ans = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].second <= w)
		{
			ans += a[i].first;
			w -= a[i].second;
		}
		else
		{
			ans += w * ((double)a[i].first / a[i].second);
			return ans;
		}
	}
	return ans;
}

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int n = 3, w = 50;

	pair<int, int> a[] = {make_pair(120, 30), make_pair(100, 20), make_pair(60, 10)};

	cout << solve(a, n, w);

	return 0;
}