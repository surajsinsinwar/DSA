#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int solve(vector<pair<int, int>> a, int n)
{
	sort(a.begin(), a.end(), cmp);
	int ans = 1, prev = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i].first >= a[prev].second)
		{
			ans++;
			prev = i;
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
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<pair<int, int>> v(n);

		for (int i = 0; i < n; i++)
			cin >> v[i].first;
		for (int i = 0; i < n; i++)
			cin >> v[i].second;

		cout << solve(v, n) << "\n";

	}

	return 0;
}