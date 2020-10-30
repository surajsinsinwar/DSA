#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int n = s.length();
	vector<int> count(26, 0);

	for (int i = 0; i < n; i++) {
		count[s[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {
		if (count[s[i] - 'a'] > 1) {
			return i;
		}
	}
	return -1;
}

int main() {

	string str = "geeksforgeeks";
	cout << "Index of leftmost repeating character:" << endl;
	cout << solve(str) << endl;

	return 0;
}