
/*
Problem: Count number of pairs of sequence of distinct integer sum equal to Q
Description
Given a sequence of distinct integers a_1, a_2, ..., a_n and an integer Q. Count number M of pairs (i, j) 
such that 1 ≤ i< j ≤ n, and a_i + a_j = Q
Input
•Line 1: contains two integers nand Q
•Line 2: contains a_1, a_2, ..., a_n
Ouput
•Write the value of M
Example
Input
5 8
4 6 5 3 2
Output
2
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, Q;
    cin >> n >> Q;
    vector<int> a;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int result = 0;
    // O(n^2) approach
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i+1; j <= n; j++)
    //     {
    //         if (a[i] + a[j] == Q) result++;
    //     }
        
    // }

    // --------------
    // O(n) approach
    unordered_set<int> set; // lưu trữ các số
    unordered_set<int> seen; // lưu trữ các pair mà đã gặp trước đó
    for(int i = 1; i <= n; i++) {
        int num = a[i];
        if (set.find(Q-num)!=set.end() && seen.find(num) == seen.end())
        {
            result++;
            seen.insert(Q-num);
            seen.insert(num);
        }
        set.insert(num);
    }
    cout << result << endl;
    return 0;
}