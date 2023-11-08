/*
Problem: Connected Components of undirected graphs
Description
Given a undirected graph G=(V,E) where V={1,. . .,N} is the number of nodes and the set E has M edges. 
Compute the number of connected components of G.
Input
Line 1: two positive integers N and M (1 <= N <= 10^5, 1 <= M <= 10^5)
Line i+1 (i=1, . . .,M): contains two positive integers u and v which are endpoints of i_th edge
Output
Write the number of connected components of G.

Example
Input
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8

Output
3
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> visited(N, 0);
int n, m;

void input() {
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u) {
    visited[u] = 1;
    for (const int &v : adj[u]) // duyệt theo địa chỉ của v, thêm const để đảm bảo không thể thay đổi giá trị của v
    {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    cout << count;
    return 0;
}