/*
Problem: TSP
Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  
A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. 
Find the itinerary for that person so that the total travel distance is minimal.
Input
Line 1: a positive integer n (1 <= n <= 20)
Linr i+1 (i = 1, . . ., n): contains the i
th
 row of the distance matrix x (elements are separated by a SPACE character)
Output
Write the total travel distance of the optimal itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7
*/

#include<bits/stdc++.h>
using namespace std;

int n;
int C[21][21];
int c_min = INT_MAX;
int isVisited[21];
int f = 0; // f = c[1][x] + c[x][y] + ... 
int path[21];
int result = INT_MAX;

void Try(int k) {
    for (int i = 1; i <= n; i++)
    {
        if (isVisited[i] == 0)
        {
            path[k] = i;
            f += C[path[k-1]][i];
            isVisited[i] = 1;
            if (k == n) {
                result = min(result, f+C[path[k]][1]);

            }
            else if (f + c_min * (n-k+1) < result) Try(k+1);
            isVisited[i] = 0;
            f -= C[path[k-1]][i];
        }
        
    }
    

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> C[i][j];
            c_min = min(c_min, C[i][j]);
        }
    }
    isVisited[1] = 1;
    path[1] = 1;
    Try(2);
    cout << result << endl;    
    return 0;
}