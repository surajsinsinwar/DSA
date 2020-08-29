#include<bits/stdc++.h>

using namespace std;

void leftSmallest(vector<int> v, std::vector<int> &left, int n)
{
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return;
}

void rightSmalest(vector<int> v, std::vector<int> &right, int n)
{
    stack<int> st;

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> v(n), left(n), right(n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    leftSmallest(v, left, n);
    rightSmalest(v, right, n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", right[i]);
    }

    int ans = 0, temp;
    for(int i = 0; i < n; i++)
    {
        temp = (right[i] - left[i] - 1) * v[i];
        ans = max(ans, temp);
    }

    printf("%d\n", ans);
 
    return 0;
}