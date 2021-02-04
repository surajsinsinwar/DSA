#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> v[], vector<bool> &visited, int prev, int n) {
	visited[n] = true;

	for (auto i : v[n]) {
		if (visited[i] == false) {
			visited[i] = true;
			if (solve(v, visited, n, i)) {
				return true;
			}
		}
		else if (i != prev) {
			return true;
		}
	}

	return false;
}

void addEdge(vector<int> v[], int a, int b) {
	v[a].push_back(b);
	v[b].push_back(a);
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
	// addEdge(v, 1, 2);
	// addEdge(v, 2, 3);
	// addEdge(v, 1, 3);
	// addEdge(v, 3, 4);
	// addEdge(v, 2, 4);

	vector<bool> visited(n, false);
	int prev = 0;

	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			if (solve(v, visited, -1, i)) {
				flag = true;
				break;
			}
		}
	}

	flag ? cout << "YES" : cout << "NO";

	return 0;
}