#include<bits/stdc++.h>
using namespace std;

void reverseStr(string &s, int start, int end) {
	while (start < end) {
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return;
}

string solve(string s) {
	int n = s.length();
	int start = 0, end, mid;
	char temp;
	for (end = 0; end < n; end++) {
		if (s[end] == ' ') {
			reverseStr(s, start, end - 1);
			start = end + 1;
		}
	}

	reverseStr(s, start, end - 1);

	reverseStr(s, 0, n - 1);

	return s;
}

int main() {
	string s = "Welcome to Gfg";
	cout << solve(s);

	return 0;
}