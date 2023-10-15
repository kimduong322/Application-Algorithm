/*
Description
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 10^9+7.
Example
Input
3  5
Output
10
*/

#include<bits/stdc++.h>
using namespace std;
int n, k;
const int Q = 1e9+7;

// dynamic programming version begin
int memory[1000][1000];
int C_dynamicVer(int k, int n) {
    // base-case
    if (k == 0 || n == 0 || k == n) return memory[k][n] = 1;
    if (k == 1) return memory[k][n] = n;
    if (k < n) {
        
        if (memory[k][n] != 0) {
            return memory[k][n];
        }

        int result = C_dynamicVer(k, n-1) + C_dynamicVer(k-1, n-1);
        result = result % Q;
        memory[k][n] = result;
        return result;
    }
}

int main() {
    cin >> k >> n;
    cout << C_dynamicVer(k, n) << endl;
    return 0;
}