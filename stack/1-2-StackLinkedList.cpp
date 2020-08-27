#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node* next;
};

node* head = NULL;

void push(int key){
	node* temp = new node();
	temp -> data = key;
	temp -> next = NULL;

	if(head == NULL){
		head = temp;
		return;
	}

	temp -> next = head;
	head = temp;
	return;
}

void pop(){
	if(head == NULL){
		cout<<"Stack is Empty"<<endl;
		return;
	}

	head = head -> next;
	return;
}

void printStack(){
	if(head == NULL){
		cout<<"Stack is Empty"<<endl;
		return;
	}

	node* temp = head;

	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	return;
}

void top(){
	if(head == NULL){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	
	cout<<head -> data<<endl;
	return;
}

void IsEmpty(){
	if(head == NULL){
		cout<<"Stack is Empty"<<endl;
		return;
	}
	cout<<"Stack is not Empty"<<endl;
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