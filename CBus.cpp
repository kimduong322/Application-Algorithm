/*
Problem: CBUS
Description
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). 
There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, 
there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the 
traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, 
serving n passengers and coming back to point 0. 
Input
Line 1 contains n and k (1≤n≤11,1≤k≤10)
Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include<bits/stdc++.h>
using namespace std;
//1≤n≤11,1≤k≤10
int n, Q;
int load; // so nguoi tren xe load <= Q
int c[23][23];
int cmin = INT_MAX; 
int f;
int f_best = INT_MAX;
int x[23];
int isVisited[23];

void input() {
    cin >> n >> Q;
    int N = 2*(n+1)-1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &c[i][j]);
            // bắt buộc phải có điều kiện i != j, vì nếu không có thì cmin luôn bằng 0, 
            // vì vậy thuật toán sẽ không áp dụng được cơ chế nhánh cận
            if(i != j) cmin = min(cmin, c[i][j]); 
        }
    }
}

bool check(int k, int u) {
    if (isVisited[u]) return false;
    if (u > n) { 
        if (!isVisited[u-n]) return false;
    } else {
        if (load >= Q) return false;
    }
    return true;
}


void Try(int k) {
    for (int u = 1; u <= 2*n; u++)
    {
        if(check(k, u)) {
            x[k] = u;
            f += c[x[k-1]][u];
            isVisited[u] = 1;
            if (u <= n) load++; else load--;
            if (k == 2*n)
            {
                f_best = min(f_best, f+c[u][0]);
            } else {
                if (f+(2*n+1-k)*cmin < f_best)
                {
                    Try(k+1);
                }
            }
            if (u <= n) load--; else load++;
            isVisited[u] = 0;
            f -= c[x[k-1]][u];
        }
    }
    
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    input();
    for (int i = 0; i <= 2*n; i++) isVisited[i] = 0;
    isVisited[0] = 1;
    x[0] = 0;
    Try(1);
    
    cout << f_best << endl;
    return 0;
}