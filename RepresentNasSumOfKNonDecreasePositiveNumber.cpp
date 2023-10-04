/*
Problem: Generate ways to represent n by sum of k non-decreasing positive integers
Description
Given two positive integers k and n. Write a program to generate (x_1, x_2, ..., x_k)
such that x_1 <= x_2 <= .. <= x_k and x_1 + x_2 + ... +x_k = n
Input
Line 1 contains: k and n (1 <= k <= n <= 40)
Output
Each line contains: x

separated by a SPACE character
Example
Input
3  7
Output
1 1 5
1 2 4
1 3 3
2 2 3
*/

#include<bits/stdc++.h>
using namespace std;
int k, n;
vector<int> x(k+1);
int f = 0; // f = x_1 + x_2 + ...
void Try(int m, int start) {
    for (int c = start; c <= (n-f); c++)
    {
        x[m] = c;
        f += x[m];
        if (m == k)
        {
            if (f == n) {
                for (int i = 1; i <= k; i++)
                {
                    printf("%d ", x[i]);
                }
                printf("\n");
            }
        } else Try(m+1, c);
        f -= x[m];
    }
    
}

int main() {
    cin >> k >> n;
    x.resize(k+1);
    Try(1, 1);
    return 0;
}