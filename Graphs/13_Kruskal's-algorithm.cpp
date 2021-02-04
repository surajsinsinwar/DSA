#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int s;
	int d;
	int w;

	node(int _s, int _d, int _w) {
		this -> s = _s;
		this -> d = _d;
		this -> w = _w;
	}
};

bool cmp(node* a, node* b) {
	return a -> w < b -> w;
}

int find(vector<int> &p, int x) {
	if (x == p[x]) {
		return x;
	}
	return p[x] = find(p, p[x]);
}

void Union(vector<int> &p, vector<int> &r, int x, int y) {
	if (r[x] > r[y]) {
		p[y] = x;
	}
	else if (r[x] < r[y]) {
		p[x] = y;
	}
	else {
		p[y] = x;
		r[x]++;
	}
}

int solve(vector<node*> v, int n, int e) {
	sort(v.begin(), v.end(), cmp);

	vector<int> p(e), r(e, 0);

	for (int i = 0; i < e; i++) {
		p[i] = i;
	}

	int in = 0, i = 0, sum = 0;

	while (in < n - 1 && i < e) {
		int x = find(p, v[i] -> s);
		int y = find(p, v[i] -> d);
		cout << x << " " << y << "\n";

		if (x != y) {
			Union(p, r, x, y);
			sum += v[i] -> w;
			in++;
		}

		i++;
	}

	cout << sum << " ";

	return sum;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;
	int e = 7;

	vector<node*> v(7);

	v[0] = new node(0, 1, 10);
	v[1] = new node(0, 2, 8);
	v[2] = new node(1, 2, 5);
	v[3] = new node(1, 3, 3);
	v[4] = new node(2, 3, 4);
	v[5] = new node(2, 4, 12);
	v[6] = new node(3, 4, 15);

	cout << solve(v, n, e);

	return 0;
}