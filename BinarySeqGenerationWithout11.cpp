/*
Problem: Binary sequences generation without consecutive 11
Description
Given an integer n, write a program that generates all binary sequences without consecutive 11 
in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
Example
Input
3
Output
000
001
010
100
101
*/

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> result(n+1);

void Try(int k) {
    for (int c = 0; c <= 1; c++)
    {
        if (c == 1 && result[k-1] == 1 & k-1 != 0) continue;
        else {
            result[k] = c;
            if (k == n) {
                for (int j = 1; j <= n; j++)
                {
                    printf("%d", result[j]);
                }
                printf("\n");
            } else Try(k+1);
        }
    }
    
}

int main() {
    cin >> n;
    result.resize(n+1);
    Try(1);
    return 0;
}