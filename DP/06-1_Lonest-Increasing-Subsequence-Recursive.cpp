
// Time Complexcity O(2^n)

#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n, vector<int> v)
{
    if(n == 0)
        return v.size();
    int temp = solve(a, n - 1, v);
    if(v.empty() || *v.rbegin() < a[n - 1])
        v.push_back(a[n - 1]);
        temp = max(temp, solve(a, n - 1, v));
    return temp;
}

int main()
{
    int a[] = {4, 10, 6, 5, 8, 11, 2, 20};
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> v;

    cout << solve(a, n, v);

    return 0;
}