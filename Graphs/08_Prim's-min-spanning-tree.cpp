#include <bits/stdc++.h>
using namespace std;
#define n 4

int primMST(int v[n][n]) {
	vector<int> dis(n, INT_MAX);
	vector<bool> flag(n, 0);

	dis[0] = 0;

	int ma = 0;

	for (int i = 0; i < n; i++) {
		int in = -1;

		for (int i = 0; i < n; i++) {
			if (!flag[i] && (in == -1 || dis[in] > dis[i])) {
				in = i;
			}
		}

		flag[in] = 1;
		ma += dis[in];

		for (int i = 0; i < n; i++) {
			if (v[in][i] != 0 && !flag[i]) {
				dis[i] = min(dis[i], v[in][i]);
			}
		}
	}

	return ma;
}

int main()
{
	int graph[n][n] = { { 0, 5, 8, 0},
		{ 5, 0, 10, 15 },
		{ 8, 10, 0, 20 },
		{ 0, 15, 20, 0 },
	};

	cout << primMST(graph);

	return 0;
}
