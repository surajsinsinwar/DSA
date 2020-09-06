
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree3233/1

#include<bits/stdc++.h>

using namespace std;

//User function Template for C++


/**
 *  ith value in adj vector contains information between the node connected to it and weight between them.
 *  Example. for a value 2 3 1, Node 2 and Node 3 has weight 1. adj[2] = {3,1} and adj[3] = {2,1}.
 *  n -> number of nodes
 *  m -> total number of edges
 *  return the mst value
*/

int find(int x,int par[])
{
    if(x == par[x])
        return x;
    
    par[x] = find(par[x],par);
    return par[x];
}

bool union_(int x,int y,int par[],int rank[])
{
    int p1 = find(x,par);
    int p2 = find(y,par);
    
    if(p1 == p2)
        return false;
    
    if(rank[p1] == rank[p2])
    {
        par[p1] = p2;
        rank[p2]++;
    }
    else if(rank[p1] < rank[p2])
    {
        par[p1] = p2;
    }
    else
        par[p2] = p1;
        
    return true;
    
}

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) {
       
    int par[n+1];
    int rank[n+1];
    for(int i=0; i<n; i++)
    {
        par[i+1] = i+1;
        rank[i+1] = 0;
    }
    
    long int ans = 0;
    
    vector<pair<long int,pair<int,int>>>adj_l;
    
    for(int i=0; i<n; i++)
    {
        for(auto ele : adj[i+1])
        {
            adj_l.push_back({ele.second,{i+1,ele.first}});
        }
    }
    
    sort(adj_l.begin(),adj_l.end());
    
    int edge = 0;
    int len = 2*m;
    for(int i=0; i<len && edge<(n-1); i++)
    {
        int x = adj_l[i].second.first;
        int y = adj_l[i].second.second;
        long int w = adj_l[i].first;
        
        if(union_(x,y,par,rank))
        {
            edge++;
            ans += w;
        }
    }
    
    return ans;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;

    vector<pair<int, long long int>> adj[100009];

    while(t--) {

        int n,m;
        cin>>n>>m;

        int u,v;
        long long w;
        for(int i=0; i<m; i++) {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        cout<<kruskalDSU(adj, n, m)<<endl;

        for(int i=0; i<=n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
  // } Driver Code Ends