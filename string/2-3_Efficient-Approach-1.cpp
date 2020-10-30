#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int n = s.length();
	vector<int> count(26, -1);

	int mi = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (count[s[i] - 'a'] == -1) {
			count[s[i] - 'a'] = i;
		}
		else {
			mi = min(mi, count[s[i] - 'a']);
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