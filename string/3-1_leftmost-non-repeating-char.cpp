#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	int n = s.length();
	bool flag = 1;
	int j, i;
	for (i = 0; i < n; i++) {
		flag = 1;
		for (j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				flag = 0;
				break;
			}
		}
		if (flag)
			return i;
	}
	return -1;
}

int main() {

	string str = "geeksforgeeks";
	cout << "Index of leftmost repeating character:" << endl;
	cout << solve(str) << endl;

	return 0;
}