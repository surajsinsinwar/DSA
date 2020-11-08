#include<bits/stdc++.h>
using namespace std;

void solve(string txt, string pat) {

	int n = txt.length();
	int m = pat.length();
	int j;

	vector<int> v(m);
	v[0] = 0;

	for (int i = 1; i < m; i++) {
		j = v[i - 1];
		while (j != 0 && txt[i] != pat[j]) {
			j = v[j - 1];
		}
		if (pat[i] == pat[j]) {
			j++;
		}
		v[i] = j;
		cout << v[i] << " ";
	}
	cout << "\n";

	j = v[0];
	for (int i = 0; i < n; i++) {
		while ((j != 0 && txt[i] != pat[j]) || (j == m)) {
			j = v[j - 1];
		}
		if (txt[i] == pat[j]) {
			j++;
		}
		if (j == m) {
			cout << i - j + 1 << " ";
		}
	}

	return;
}

int main() {
	string txt = "aaaaaaaaaa", pat = "aa";
	solve(txt, pat);

	return 0;
}