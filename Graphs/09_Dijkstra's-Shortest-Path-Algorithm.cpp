#include <bits/stdc++.h>
using namespace std;
#define n 4

vector<int> djikstra(int v[n][n], int src) {
	vector<int> dis(n, INT_MAX);
	vector<bool> flag(n, 0);

	dis[0] = 0;

	for (int i = 0; i < n; i++) {
		int in = -1;
		for (int i = 0; i < n; i++) {
			if (!flag[i] && (in == -1 || dis[i] < dis[in])) {
				in = i;
			}
		}

		flag[in] = 1;

		for (int i = 0; i < n; i++) {
			if (v[in][i] != 0 && !flag[i]) {
				dis[i] = min(dis[i], dis[in] + v[in][i]);
			}
		}
	}

	return dis;
}

int main()
{
	int graph[n][n] = { { 0, 50, 100, 0},
		{ 50, 0, 30, 200 },
		{ 100, 30, 0, 20 },
		{ 0, 200, 20, 0 },
	};

	for (int x : djikstra(graph, 0)) {
		cout << x << " ";
	}

	return 0;
}
