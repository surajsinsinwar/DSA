#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
    int b[n] = {1}, ma = 1;

    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            if(a[i] > a[j])
                b[i] = max(b[i], b[j] + 1);
        }
        ma = max(ma, b[i]);
    }
    return ma;
}

int main()
{
    int a[] = {4, 10, 6, 5, 8, 11, 2, 20};
    int n = sizeof(a) / sizeof(a[0]);

    cout << solve(a, n);

    return 0;
}