#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> v[], int n) {
	vector<int> count(n, 0);

	for (int i = 0; i < n; i++) {
		for (auto j : v[i]) {
			count[j]++;
		}
	}

	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (count[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		cout << temp << " ";

		for (auto i : v[temp]) {
			count[i]--;
			if (count[i] == 0) {
				q.push(i);
			}
		}
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
	addEdge(v, 0, 2);
	addEdge(v, 1, 2);
	addEdge(v, 2, 3);
	addEdge(v, 1, 3);
	addEdge(v, 3, 4);
	addEdge(v, 2, 4);

	solve(v, n);

	return 0;
}