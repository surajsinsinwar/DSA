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

void Union(int x, int y, vector<int> &v, vector<int> &rank)
{
    x = find(x, v);
    y = find(y, v);

    if(x == y)
    {
        return;
    }

    else if(rank[x] < rank[y]) v[x] = y;
    else if(rank[y] < rank[x]) v[y] = x;
    else v[y] = x, rank[x]++;

    return;
}

int32_t main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> v(n), rank(n);

    for(int i = 0; i < n; i++)
    {
        v[i] = i;
        rank[i] = 0;
    }

    Union(0, 2, v, rank);
    Union(1, 3, v, rank);
    Union(1, 2, v, rank);
    printf("%d %d\n", find(0, v), find(3, v));

    return 0;
}