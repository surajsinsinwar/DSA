#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int n = s.length();
	vector<bool> count(26, 0);

	int mi = INT_MAX;
	for (int i = n - 1; i >= 0; i--) {
		if (count[s[i] - 'a']) {
			mi = i;
		}
		else {
			count[s[i] - 'a'] = 1;
		}
	}
	if (mi > n) mi = -1;
	return mi;
}

int main() {

	string str = "geeks";
	cout << "Index of leftmost repeating character:" << endl;
	cout << solve(str) << endl;

	return 0;
}