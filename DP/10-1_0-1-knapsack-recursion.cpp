#include<bits/stdc++.h>
using namespace std;

int solve(int v[], int w[], int n, int wt){
    if(n == 0)
        return 0;
    int temp = solve(v, w, n - 1, wt);
    if(wt >= w[n - 1])
        temp = max(temp, solve(v, w, n - 1, wt - w[n - 1]) + v[n - 1]);
    return temp;
}

int main(){

    int n = 4, wt = 10;
    int v[] = {10, 40, 30, 50}, w[] = {5, 4, 6, 3};

    cout << solve(v, w, n, wt) << "\n";
    return 0;
}