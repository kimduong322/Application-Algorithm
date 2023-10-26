/*
Denote X = X1, X2, …, Xn, a subsequence of X is created by removing some element from X.  
Given two sequences X = X1, X2, …, Xn and Y = Y1, Y2, …, Ym. 
Find a common subsequence of X and Y such that the length is the longest.

Input
Line 1: two positive integers n and m (1 <= n,m <= 10000)
Line 2: n integers X1, X2, …, Xn
Line 3: m integers Y1, Y2, …, Ym
Output
Length of the longest subsequence of X and Y
Example 
Input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Output
5
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4+5;
int n, m;
int X[MAXN], Y[MAXN];
int mem[MAXN][MAXN];
// int LCS = -1e9; // longest common subsequence

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> Y[i];
    }
}

/*
    LCS(int i, int j) find the longest common subsequence in X[1..i] and Y[1..j]
    Dynamic Programming Version
    Pass: 3/5 test cases
*/
int LCS(int i, int j) {
    // base
    if (i == 0 || j == 0) return 0;
    
    // if existed
    if (mem[i][j] != -1) return mem[i][j];

    if (X[i] == Y[j])
    {
        return mem[i][j] = 1 + LCS(i-1, j-1);
    }
    return mem[i][j] = max(LCS(i - 1, j), LCS(i, j - 1));
}

/*
    LCS_Tab() find the longest common subsequence in X and Y
    Using tabulation dp[][]
    Pass: 5/5 testcases
*/
int dp[10001][10001];
int LCS_Tab() {
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            } 
            else if (X[i] == Y[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // memset(mem, -1, sizeof(mem));
    input();
    // cout << LCS(n, m) << endl;
    cout << LCS_Tab() << endl;
    return 0;
}