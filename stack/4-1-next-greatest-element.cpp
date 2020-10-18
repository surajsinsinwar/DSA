#include<bits/stdc++.h>
using namespace std;

void nextGreatestElement(vector<int> v, int n)
{
    stack<int> st;

    for (int i = 0; i < n ; i++)
    {
        while (!st.empty() && st.top() <= v[i])
        {
            st.pop();
        }
        st.empty() ? printf("-1 ") : printf("%d ", st.top());
        st.push(v[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    nextGreatestElement(v, n);

    return 0;
}