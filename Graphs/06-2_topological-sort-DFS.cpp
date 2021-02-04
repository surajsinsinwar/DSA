#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> v[], vector<bool> &visited, stack<int> &st, int n) {
	visited[n] = true;

	for (auto i : v[n]) {
		if (!visited[i]) {
			solve(v, visited, st, i);
		}
	}

	st.push(n);
}

void dfs(vector<int> v[], int n) {
	vector<bool> visited(n, 0);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			solve(v, visited, st, i);
		}
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return;
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
	addEdge(v, 1, 3);
	addEdge(v, 2, 3);
	addEdge(v, 3, 4);
	addEdge(v, 2, 4);

	dfs(v, n);

	return 0;
}