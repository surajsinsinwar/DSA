#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int n = s.length();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				return i;
			}
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