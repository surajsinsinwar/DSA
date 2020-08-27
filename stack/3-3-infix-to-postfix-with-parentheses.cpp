#include<bits/stdc++.h>

using namespace std;

stack <int> st;

bool operent(char c){
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')  ? true : false;
}

bool opening(char c){
	return c == '{' || c == '[' || c == '(' ? true : false;
}

bool closing(char c){
	return c == '}' || c == ']' || c == ')' ? true : false;
}

bool HigherOrEqualPree(char top, char c){
	if(c == '^'){
		return top == '^' ? true : false;
 	}
 	else if(c == '*' || c =='/'){
 		return top == '^' || top == '*' || top == '/' ? true : false;
 	}
 	else return true;
}


string InfixToPostfix(string arr){
	string s;
	int n = arr.length();
	for(int i = 0; i < n; i++){
		if(operent(arr[i])){
			s.push_back(arr[i]);
		}
		else if(opening(arr[i])){
			st.push(arr[i]);
		}
		else if(closing(arr[i])){
			while(!opening(st.top())){
				s.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && HigherOrEqualPree(st.top(), arr[i])){
				if(opening(st.top())){
					break;
				}
				s.push_back(st.top());
				st.pop();
			}
			st.push(arr[i]);
		}
	}
	while(!st.empty()) s.push_back(st.top()) , st.pop();

	return s;
}

int main(){
	
	string arr;
	cin >> arr;

	cout << InfixToPostfix(arr) << endl;

	return 0;
}