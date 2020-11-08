#include<bits/stdc++.h>
using namespace std;

int const CHAR = 256;

int solve(string s) {
	vector<int> v(CHAR, -1);

	int n = s.length();

	for (int i = 0; i < n; i++) {
		if (v[s[i]] == -1)
			v[s[i]] = i;
		else
			v[s[i]] = -2;
	}

	int ma = INT_MAX;

	for (int i = 0; i < CHAR; i++) {
		if (v[i] >= 0)
			ma = min(ma, v[i]);
	}

	return (ma != INT_MAX ? ma : -1);
}

int main() {
	string str = "geeksforgeeks";
	cout << "Index of leftmost non-repeating element:" << endl;
	cout << solve(str) << endl;

	return 0;
}