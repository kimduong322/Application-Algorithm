#include<bits/stdc++.h>
using namespace std;
/*
Problem: Range Minimum Query
Description
Given a sequence of n integers a_0,. . .,a_n-1. 
We denote rmq(i,j) the minimum element of the sequence a_i, a_i+1, . . .,a_j. 
Given m pairs (i_1, j_1),. . .,(i_m, j_m), compute the sum Q = rmq(i_1, j_1) + . . . + rmq(i_m, j_m)
Input
Line 1: n (1 <=  n <= 10^6)
Line 2: a_0, . . . ,a_n-1 ( 1  <=  a_i <= 10^6)
line 3: m (1  <= m <= 10^6)
Line k+3 (k=1, . . ., m): i_k, j_k  (0  <=  i_k < j_k < n)
Output
Write the value Q
Example
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10
Output
6
-----------------------------------------------------------------------------------------------------
*/

int n, m, i, j;
int Q = 0;
// LG là số lớn nhất thoả 2^LG < N
// ví dụ: N = 10^5 thì LG = 16 vì 2^16 = 65536
// N = 10^6 => LG = 19
int LG = 19;
int st[21][1000001]; //st[j][i] là giá trị nhỏ nhất của 2^j phần tử tính từ i (min của a[i…i+2^j−1])
int A[1000001];
pair<int, int> query[1000001];

int rangeMinimum(int i, int j) {
    int min = INT_MAX;
    for (int k = i; k < j; k++) {
        if (A[k] < min)
        {
            min = A[k];
        }
        
    }
    return min;    
}

void preprocess() {
    for (int i = 0; i < n; i++) st[0][i] = A[i];
    for (int j = 1; j <= LG; j++)
    {
        for (int i = 0; i + (1 << j) -1 < n; i++)
        {
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
        }
        
    }
    
}

int rmq(int l, int r) {
    /*
    tìm k nhỏ nhất thoả mãn len< 2^(k+1)=2^k+2^k (hay nói cách khác là để chắc chắn 2 đoạn [l…l+2^k−1]
    và [r−2k+1,r] giao nhau nhưng vẫn nằm trong đoạn [l,r]).
    */
   int len = r - l + 1;
   int k = log2(len);
   return min(st[k][l], st[k][r - (1 << k) + 1]);
}

void input() {

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    for(int k = 0; k < m; k++) {
        scanf("%d %d", &i, &j);
        // Q += rangeMinimum(i, j);
        query[k] = make_pair(i, j);
    }
}

void RangeMinimumQuery() {
    preprocess();
    for (int i = 0; i < m; i++)
    {
        Q += rmq(query[i].first, query[i].second);
    }
    cout << Q << endl;
}

int main() {

    input();
    RangeMinimumQuery();
    return 0;
}