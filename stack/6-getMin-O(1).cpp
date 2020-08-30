#include<bits/stdc++.h>
using namespace std;

stack<int> st, temp;

void push(int m)
{
    if(st.empty() || m <= temp.top())
    {
        temp.push(m);
    }
    st.push(m);
    return;
}

void pop()
{
    if(st.empty())
    {
        return;
    }

    if(st.top() == temp.top())
    {
        temp.pop();
    }
    st.pop();

    return;
}

void getmin()
{
    if(st.empty())
    {
        return;
    }

    printf("%d\n", temp.top());

    return;
}

int main()
{

    int q, m;
    scanf("%d", &q);

    while(q--)
    {
        printf("\n1 - push\n2 - pop\n3 - getmin\n");
        scanf("%d", &m);
        switch(m)
        {
            case 1:
                scanf("%d", &m);
                push(m);
                break;
            case 2:
                pop();
                break;
            case 3:
                getmin();
                break;
        }
    }

    return 0;
}