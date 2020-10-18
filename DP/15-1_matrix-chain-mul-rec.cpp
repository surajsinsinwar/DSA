#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int i, int j) {
    if (i + 1 == j)
        return 0;
    int temp = INT_MAX;
    for (int k = i + 1; k < j; k++)
        temp = min(temp, solve(a, i, k) + solve(a, k, j) + a[i] * a[k] * a[j]);
    return temp;
}

int main() {
    int a[] = {20, 10, 30, 40};
    int n = sizeof(a) / sizeof(a[0]);

    cout << solve(a, 0, n - 1);

    return 0;
}