/*
Problem: Gen k-combinations of 1 2 - n
Description
Given 2 positive integers k and n. Write a program tat generates all k-combinations 
of 1, 2, ..., n in a lexicographic order.

Example
Input
2 4
Output
1 2
1 3
1 4
2 3
2 4
3 4
*/

#include<bits/stdc++.h>
using namespace std;

int n, m; //mCn
vector<int> result(m+1);
vector<int> isMarked(n+1, 0);

void Try(int k, int start) {

    for (int c = start; c <= n ; c++)
    {
        if (isMarked[c] == 0) {
            result[k] = c;
            isMarked[c] = 1;
            if (k == m-1) {
                for (int j = 0; j < m; j++)
                {
                    printf("%d ", result[j]);
                }
                printf("\n");
            } else Try(k+1, c+1);
            isMarked[c] = 0;
        }
        
    }
    
}

int main() {
    cin >> m >> n;
    result.resize(m+1);
    isMarked.resize(n+1, 0);
    Try(0, 1);
    return 0;
}