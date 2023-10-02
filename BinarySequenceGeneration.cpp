/*
Description
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> result(n+1);
void Try(int k) {
    for (int i = 0; i < 2; i++)
    {
        result[k] = i;
        if (k == n-1) {
            for (int j = 0; j < n; j++) {
                printf("%d", result[j]);
            }
            printf("\n");
        }
        else Try(k+1);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    result.resize(n+1);
    Try(0);   
    return 0;
}