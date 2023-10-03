/*
Problem: Permutation generation
Description
Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input 
3
Output
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 1 2 
3 2 1 
*/

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> permutations(n+1);
vector<int> isMarked(n+1, 0);

void Try(int k) {
    for (int i = 1; i <= n; i++)
    {
        if (isMarked[i]==0)
        {
            permutations[k] = i;
            isMarked[i] = 1;
            if (k == n)
            {
                for (int j = 1; j <= n; j++)
                {
                    printf("%d ", permutations[j]);
                }
                printf("\n");
            } else Try(k+1);
            isMarked[i] = 0;
        }
            
    }
    
}

int main() {
    cin >> n;
    permutations.resize(n+1);
    isMarked.resize(n+1, 0);
    Try(1);
    return 0;
}