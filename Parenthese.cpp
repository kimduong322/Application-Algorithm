/*
Problem: Parentheses
Description

Given a string containing only characters (, ), [, ] {, }. Write a program that check whether the string is correct in expression. 
Example:
([]{()}()[]): correct
([]{()]()[]): incorrect
Input
One line contains the string (the length of the string is less than or equal to 10^6)
Output
Write 1 if the sequence is correct, and write 0, otherwise
Example:
input
(()[][]{}){}{}[][]({[]()})
output
1
*/

#include<bits/stdc++.h>
using namespace std;


bool isPair(char s_i, char top_stack) {
    if (s_i == '}' && top_stack=='{') return true;
    if (s_i == ']' && top_stack=='[') return true;
    if (s_i == ')' && top_stack=='(') return true;
    return false;
}

bool solve(string seriesOfParentheses) {
    stack<char> s;
    for (int i = 0; i < seriesOfParentheses.size(); i++)
    {
        if (seriesOfParentheses[i] == '(' || seriesOfParentheses[i] == '{' || seriesOfParentheses[i] == '[')
        {
            s.push(seriesOfParentheses[i]);
        }
        else {
            if (s.empty() || (!isPair(seriesOfParentheses[i], s.top())))
            {
                return false;
            }
           s.pop();
        }
    }
    if (!s.empty())  
    {
        return false;
    } 
    return true;
}

int main() {

    string seriesOfParentheses;
    cin >> seriesOfParentheses;
    
    cout << solve(seriesOfParentheses) << endl;
    return 0;
}