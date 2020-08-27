#include <iostream>
#include <stack>

using namespace std;

int maxArea(int a[],int n){
  stack<int> s;
  int tp,i;
  int max_area;
  i=0;
  max_area=0;
  while(i<n){
    if(s.empty() || a[s.top()]<=a[i]){
      s.push(i++);
    }
    else{
      tp=s.top();
      s.pop();
      int area= a[tp] * (s.empty() ? i : i - s.top() - 1);
      if(area>max_area)
	max_area=area;
    }
  }
  
  while(s.empty()==false){
    tp=s.top();
    s.pop();
    int area= a[tp] * (s.empty() ? i : i - s.top() - 1);
    if(area > max_area)
      max_area=area;
  }
  return max_area;
}

int main(){
	int arr[100000], n;
    cin >> n;

    for(int j=0;j<n;j++) cin >> arr[j];

    cout<<maxArea(arr,n)<<endl;

	return 0;
}
