#include<bits/stdc++.h>
using namespace std;

int BS(std::vector<int> v, int val)
{
    int l = 0, r = v.size() - 1, mid;
    while(r > l)
    {
        mid = (r + l) / 2;
        if(v[mid] >= val && (mid - 1 < 0 || v[mid - 1] < val))
            return mid;
        else if(v[mid] < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

int solve(vector<int> a, int n)
{
    vector<int> b;
    b.push_back(a[0]);
    int index;

    for(int i = 1; i < n; i++)
    {
        if(a[i] > *b.rbegin())
        {
            b.push_back(a[i]);
        }
        else
        {
            index = BS(b, a[i]);
            b[index] = a[i];
        }
    }

    return b.size();
}

int main()
{
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%d\n", solve(a, n));

    return 0;
}