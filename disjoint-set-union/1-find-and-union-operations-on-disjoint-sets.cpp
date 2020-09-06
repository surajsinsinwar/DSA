#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int> v)
{
    if(v[x] == x)
    {
        return x;
    }
    return find(v[x], v);
}

void Union(int x, int y, vector<int> &v)
{
    x = find(x, v);
    y = find(y, v);

    if(x == y)
    {
        return;
    }
    v[y] = x;
    return;
}

int32_t main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        v[i] = i;
    }

    Union(0, 2, v);
    Union(1, 3, v);
    Union(1, 2, v);
    printf("%d %d\n", find(0, v), find(3, v));

    return 0;
}