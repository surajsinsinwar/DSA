#include<bits/stdc++.h>
using namespace std;

int firstCircularTour(int petrol[], int distance[], int n)
{
    int curr_petrol = 0, index = 0;

    for(int i = 0; i < n; i++)
    {
        curr_petrol += (petrol[i] - distance[i]);
        if(curr_petrol < 0)
        {
            index = i + 1;
            curr_petrol = 0;
        }
    }

    return (index < n ? index + 1 : -1);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *petrol = new int[n], *distance = new int[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &petrol[i]);
        scanf("%d", &distance[i]);
    }

    printf("%d\n", firstCircularTour(petrol, distance, n));

    return 0;
}