#include <bits/stdc++.h>
using namespace std;
#define n 4

vector<long long> solve(int v[n][n], int s) {
	vector<long long> dis(n, INT_MAX);

	dis[s] = 0;

	for (int count = 0; count < n - 1; count++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (v[i][j] != 0) {
					dis[j] = min(dis[j], dis[i] + v[i][j]);
				}
			}
		}
	}

	return dis;
}

int main()
{
	int graph[n][n] = { { 0, -1, 100, 0},
		{ -1, 0, 30, 200 },
		{ 100, 30, 0, 20 },
		{ 0, 200, 20, 0 },
	};

	for (int x : solve(graph, 0)) {
		cout << x << " ";
	}

	return 0;
}
