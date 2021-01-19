#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> adj[], vector<bool> &visited, int n) {
	if (visited[n]) {
		return;
	}

	visited[n] = true;
	cout << n << " ";

	for (auto i : adj[n]) {
		if (visited[i] == false) {
			solve(adj, visited, i);
		}
	}

	return;
}

void addEdge(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int v = 5;
	vector<int> adj[v];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 4);
	addEdge(adj, 2, 4);

	vector<bool> visited(v, false);

	for (int i = 0; i < v; i++) {
		if (visited[i] == false) {
			solve(adj, visited, i);
		}
	}

	return 0;
}