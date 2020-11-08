#include<bits/stdc++.h>
using namespace std;

void solve(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();

	int i, j;
	bool flag;

	for (i = 0; i < n - m + 1;) {
		if (txt[i] == pat[0]) {
			flag = 1;
			for (j = 0; j < m; j++) {
				if (txt[i + j] != pat[j]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				cout << i << " ";
			}

			if (j == 0)
				i++;
			else
				i += j;
		}
		else {
			i++;
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