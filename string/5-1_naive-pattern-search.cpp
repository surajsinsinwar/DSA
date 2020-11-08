#include<bits/stdc++.h>
using namespace std;

void solve(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();

	bool flag;

	for (int i = 0; i < n - m + 1; i++) {
		if (txt[i] == pat[0]) {
			flag = 1;
			for (int j = 0; j < m; j++) {
				if (pat[j] != txt[i + j]) {
					flag = 0;
					break;
				}
			}
			if (flag)
				cout << i << " ";
		}
	}

	return;
}

int main() {
	string txt = "ABCABCD"; string pat = "ABCD";
	cout << "All index numbers where pattern found:" << " ";
	solve(txt, pat);

	return 0;
}