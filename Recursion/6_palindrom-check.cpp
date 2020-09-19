#include<iostream>
using namespace std;

bool isPalindrome(string str, int s, int e)
{
    if(s >= e)
    {
        return true;
    }

    return ((str[s] == str[e]) && isPalindrome(str, s + 1, e - 1));
}

int main()
{
    string str = "stringnirts";
    cout << (isPalindrome(str, 0, str.length() - 1) ? "True" : "False");
}