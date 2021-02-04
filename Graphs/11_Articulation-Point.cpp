#include<bits/stdc++.h>
using namespace std;

#define NIL (int)-1

int V = 5;
vector<int> adj[5];

void APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{

	static int time = 0;

	int children = 0;

	visited[u] = true;

	disc[u] = low[u] = ++time;

	vector<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i;

		if (!visited[v])
		{
			children++;
			parent[v] = u;
			APUtil(v, visited, disc, low, parent, ap);

			low[u] = min(low[u], low[v]);


			if (parent[u] == NIL && children > 1) {
				ap[u] = true;
			}
			if (parent[u] != NIL && low[v] >= disc[u]) {
				ap[u] = true;
			}
		}

		else if (v != parent[u]) {
			low[u] = min(low[u], disc[v]);
		}
	}
}

void dfs() {
	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V];

	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}

	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			APUtil(i, visited, disc, low, parent, ap);
		}
	}

	for (int i = 0; i < V; i++) {
		if (ap[i] == true) {
			cout << i << " ";
		}
	}

	return;
}

void addEdge(int a, int b) {
	adj[a].push_back(b);
	adj[b].push_back(a);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(2, 3);
	addEdge(3, 4);
	addEdge(1, 2);

	dfs();

	return 0;
}