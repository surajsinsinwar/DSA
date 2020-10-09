
// Time Complexcity O(2^n)

#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int prev, int size)
{
    if (n == 0)
        return size;
    int temp = solve(a, n - 1, prev, size);
    if (prev < a[n - 1])
        temp = max(temp, solve(a, n - 1, a[n - 1], size + 1));
    return temp;
}

int main()
{
    int a[] = {4, 10, 6, 5, 8, 11, 2, 20};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> v;

    cout << solve(a, n, 0, 0) << "\n";

    return 0;
}