#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
	int n = s.length(), len;

	vector<int> v(n);
	v[0] = 0;

	for (int i = 1; i < n; i++) {
		len = v[i - 1];
		while (len != 0 && s[i] != s[len]) {
			len = v[len - 1];
		}
		if (s[i] == s[len])
			len++;
		v[i] = len;
		cout << v[i] << " ";
	}

	return;
}

int main() {
	string s = "abcabcd";
	solve(s);

	return 0;
}