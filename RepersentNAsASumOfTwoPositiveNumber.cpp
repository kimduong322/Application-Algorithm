/*
Problem: Count the number of ways to represent n as the sum of positive integers
Description
Given a positive integer n. Write a program that computes the number Q of ways 
to represent n as the sum of positive integers
Input
Line 1: a positive integer n (1 <= n <= 50)
Output
Write the value Q mod 10^9+7
Example
Input
6
Output
11
*/
//CPP 
// Dynamic Programming

#include <bits/stdc++.h> 
using namespace std;

const int MOD = 1e9+7;
int n;

int main() 
{
    cin >> n;

    vector<int> ways(n + 1, 0);
    ways[0] = 1;
    for(int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ways[j] = (ways[j] + ways[j-i]) % MOD;
        }
    }
    cout << ways[n] << endl;
    return 0;
}
