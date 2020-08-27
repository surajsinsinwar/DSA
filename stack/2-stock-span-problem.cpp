#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	int n, span;
    scanf("%d", &n);

    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && v[st.top()] <= v[i])
        {
            st.pop();
        }
        span = st.empty() ? i + 1 : i - st.top();
        st.push(i);
        printf("%d ", span);
    }

    return 0;
}