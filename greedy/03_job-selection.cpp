#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int solve(pair<int, int> a[], int n)
{
	sort(a, a + n, cmp);
	int ma = 0;
	for (int i = 0; i < n; i++)
		ma = max(ma, a[i].second);

	vector<bool> v(ma + 1, 1);
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = a[i].second; j >= 1; j--)
		{
			if (v[j])
			{
				v[j] = 0;
				ans += a[i].first;
				break;
			}
		}
	}
	return ans;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
	int n = 3;

	pair<int, int> a[] = {make_pair(12, 1), make_pair(10, 1), make_pair(20, 2)};

	cout << solve(a, n);

	return 0;
}