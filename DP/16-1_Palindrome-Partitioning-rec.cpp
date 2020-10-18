#include<bits/stdc++.h>
using namespace std;

bool isPlalandrome(string s, int i, int j) {
    while (i < j) {
        if (s[i] == s[j])
            i++, j--;
        else
            return 0;
    }
    return 1;
}

int solve(string s, int i, int j) {
    if (isPlalandrome(s, i, j))
        return 0;
    int temp = INT_MAX;
    for (int k = i; k < j; k++)
        temp = min(temp, solve(s, i, k) + solve(s, k + 1, j) + 1);
    return temp;
}

int main() {
    string s = "geek";
    cout << solve(s, 0, s.length() - 1);

    return 0;
}