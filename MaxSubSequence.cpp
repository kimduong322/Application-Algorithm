/*
Problem: Max SubSequence
Description
Given an integers sequence a=(a_1, a_2,.., a_n). A subsequence of aa is defined to be 
a_i, a_i+1, .. a_j. The weight of a subsequence is the sum of its elements. Find the 
subsequence having the highest weight.

Input:
Line 1 contains n (1≤n≤10^6)
Line 2 contains a_1,…,a_n (−500≤a_i≤500)
Output
Write the weight of the highest subsequence found.
Example
input
10
3 -1 -3 5 2 5 0 -1 5 4
output
20
*/

#include<bits/stdc++.h>
using namespace std;
int a[1000001];

int maxMidLeft(int* a, int l, int r) {
    int res = -1e9;
    int s = 0;
    for (int i = r; i >= l; i--)
    {   
        s += a[i];
        res = max(res, s);
    }
    return res;
}

int maxMidRight(int* a, int l, int r) {
    int res = -1e9;
    int s = 0;
    for (int i = l; i <= r; i++)
    {
        s += a[i];
        res = max(res, s);
    }
    return res;
}

int maxSub(int* a, int l, int r) {
    if (l == r) {
        return a[r];
    } else {
        int mid = (l+r)/2;
        int mL = maxSub(a, l, mid);
        int mR = maxSub(a, mid+1, r);
        int mLR = maxMidLeft(a, l, mid) + maxMidRight(a, mid+1, r);
        return max(mLR, max(mL, mR));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxSub(a, 0, n-1) << endl;
    return 0;
}