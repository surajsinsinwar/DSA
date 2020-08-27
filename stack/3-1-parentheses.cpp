#include<bits/stdc++.h>

using namespace std;

stack<char> st;

bool opening_parentheses(char c){
	if(c == '[' || c == '{' || c == '(') return true;
	else return false; 
}

bool closing_parentheses(char c){
	if(c == ']' || c == '}' || c == ')') return true;
	else return false; 
}

bool st_top_parentheses_pair(char c){
	char top = st.top();
	if(c == ')' && top == '(' || c == ']' && top == ']' || c == '}' && top == '{') return true;
	else return false;
}

bool solve(string arr){

	int n = arr.length();
	for(int i = 0; i < n; i++){
		if(opening_parentheses(arr[i])){
			st.push(arr[i]);
		}
		else if(closing_parentheses(arr[i])){
			if(st.empty() || !st_top_parentheses_pair(arr[i])){
				return false;
			}
			else st.pop();
		}
	}
	return st.empty() ? true : false;
}

int main(){
	string arr;
	cin >> arr;

	solve(arr) ? cout << "YES\n" : cout << "NO\n";

	return 0;
}
