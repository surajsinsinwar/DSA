#include<bits/stdc++.h>
using namespace std;

void nextGreatestElement(vector<int> v, int n)
{
    stack<int> st;
    vector<int> ans(n);

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top() <= v[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(v[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    nextGreatestElement(v, n);

    return 0;
}