#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> v[], vector<bool> &visited, vector<bool> &st, int n) {
	visited[n] = 1;
	st[n] = 1;

	for (auto i : v[n]) {
		if (!visited[i] && solve(v, visited, st, i)) {
			return 1;
		}
		else if (st[i]) {
			return 1;
		}
	}

	st[n] = 0;
	return 0;
}

bool dfs(vector<int> v[], int n) {
	vector<bool> visited(n, 0), st(n, 0);

	for (int i = 0; i < n; i++) {
		if (!visited[i] && solve(v, visited, st, i)) {
			return 1;
		}
	}

	return 0;
}

void addEdge(vector<int> v[], int a, int b) {
	v[a].push_back(b);
	// v[b].push_back(a);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;
	vector<int> v[n];
	addEdge(v, 0, 1);
	addEdge(v, 0, 2);
	addEdge(v, 1, 2);
	addEdge(v, 2, 3);
	addEdge(v, 1, 3);
	addEdge(v, 3, 4);
	addEdge(v, 2, 4);
	addEdge(v, 4, 0);

	cout << dfs(v, n);

	return 0;
}