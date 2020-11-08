#include<bits/stdc++.h>
using namespace std;

void solve(string txt, string pat) {
	int n = txt.length();
	int m = pat.length();

	int h = 0, temp = 0;
	int d = 250, q = 11;

	bool flag;

	for (int i = 0; i < m; i++) {
		temp = ((d * temp + txt[i]) % q);
		h = ((d * h + pat[i]) % q);
	}

	int mul = 1;
	for (int i = 1; i < m; i++) {
		mul = (mul * d) % q;
	}

	for (int i = 0; i < n - m + 1; i++) {
		if (temp == h) {
			flag = 1;
			for (int j = 0; j < m; j++) {
				if (txt[i + j] != pat[j]) {
					flag = 0;
					break;
				}
			}
			if (flag)
				cout << i << " ";
		}
		if (i < n - m) {
			temp = (((d * (temp - (txt[i] * mul))) + txt[i + m]) % q);
			if (temp < 0)
				temp += q;
		}
	}
	return;
}

int main() {
	string txt = "GEEKS FOR GEEKS"; string pat = "GEEK";
	cout << "All index numbers where pattern found:" << " ";
	solve(txt, pat);

	return 0;
}