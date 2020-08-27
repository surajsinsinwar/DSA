#include<bits/stdc++.h>
#define max_size 100

using namespace std;

int arr[max_size];
int top = -1;

void push(int key){
	if(top == max_size - 1){
		cout<<"Stack Overflow"<<endl;
		return;
	}
	arr[++top] = key;
	return;
}

void pop(){
	if(top == -1){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	top--;
	return;
}

void printStack(){
	if(top == -1){
		cout<<"Stack is Empty"<<endl;
		return;
	}

	for(int i = top; i >= 0; i--){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}
int main(){
	push(10);
	push(20);
	push(30);
	pop();
	printStack();

	return 0;
}



