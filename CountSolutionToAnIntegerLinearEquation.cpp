/*
Problem: Count solutions to an integer linear equation

Description
Given a positive integer n and n positive integers a_1, a_2, ..., a_n. 
Compute the number of positive integer solutions to the equation:
a_1 * X_1 + a_2 * X_2 + ... + a_n * X_n = M
Input
Dòng 1: n và M
Dòng 2: a_1, a_2, ..., a_n
Output
   Số nghiệm nguyên dương
Ví dụ
Input
3 5
1 1 1
Output
6
*/

#include<bits/stdc++.h>
using namespace std;

int n, M;
vector<int> a;
vector<int> X;
int result = 0;
int f = 0; // f = a_1 * x_1 + ... + a_k * x_k
vector<int> t; // t[k] = a[1]+..+a[k]

void preprocess() {
    cin >> n >> M;
    a.resize(n+1);
    X.resize(n+1);
    t.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    t[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        t[i] = t[i-1] + a[i]; 
    }
    
}

void Try(int k) {
    for (int c = 1; c <= (M - f - (t[n] - t[k]))/a[k]; c++)
    {
        f += a[k]*c;
        X[k] = c;
        
        if (k == n)
        {
            if (f == M) result ++;
        } else if (k < n) Try(k+1);
        
        f -= a[k]*c;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    preprocess();
    Try(1);
    cout << result << endl;
    return 0;
}