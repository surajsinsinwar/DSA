#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
	int n = s.length();

	vector<int> v(n);
	v[0] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (s.substr(0, j) == s.substr(i - j + 1, j)) {
				v[i] = j;
			}
		}
	}

	for (auto i : v) {
		cout << i << " ";
	}

	return;
}

int main() {
	string s = "abcabcd";
	solve(s);

	return 0;
}