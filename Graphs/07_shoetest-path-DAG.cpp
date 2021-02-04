#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int val;
	int w;

	node(int _v, int _w) {
		this -> val = _v;
		this -> w = _w;
	}
};

void solve(vector<vector<node*>> v, vector<bool> &vis, stack<int> &st, int n) {
	vis[n] = true;

	for (auto i : v[n]) {
		if (vis[i -> val] == false) {
			solve(v, vis, st, i -> val);
		}
	}

	st.push(n);
	return;
}

void dfs(vector<vector<node*>> v, int n) {
	vector<bool> vis(n, 0);
	stack<int> st;

	for (int i = 0; i < n; i++) {
		if (vis[i] == false) {
			solve(v, vis, st, i);
		}
	}

	vector<int> dis(n, INT_MAX);
	dis[0] = 0;

	while (!st.empty()) {
		int temp = st.top();
		st.pop();

		if (dis[temp] != INT_MAX) {
			for (auto i : v[temp]) {
				dis[i -> val] = min(dis[i -> val], dis[temp] + i -> w);
			}
		}
	}

	for (auto i : dis) {
		cout << i << " ";
	}

	return;
}

void addEdge(vector< vector<node*> > &v, int a, int b, int w) {
	node* temp = new node(b, w);
	v[a].push_back(temp);
	// v[b].push_back(a);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 6;
	vector< vector<node*> > v(n);
	addEdge(v, 0, 1, 2);
	addEdge(v, 0, 4, 1);
	addEdge(v, 1, 2, 3);
	addEdge(v, 4, 2, 2);
	addEdge(v, 4, 5, 4);
	addEdge(v, 2, 3, 6);
	addEdge(v, 5, 3, 1);

	dfs(v, n);

	return 0;
}