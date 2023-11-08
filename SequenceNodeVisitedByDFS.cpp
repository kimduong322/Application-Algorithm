/*
Problem: Sequence of nodes visited by DFS
Description
Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
Write a program that compute the sequence of nodes visited using a DFS algorithm (the nodes are considered in a lexicographic order)

Input
Line 1: contains 2 integers n and m which are number of nodes and number of edges
Line i+1 (i = 1, ..., m): contains 2 positive integer u and v which are the end points of the ith edge

Output
Write the sequence of nodes visited by a DFS procedure (nodes a are separated by a SPACE character)
Example
Input
6 7
2 4
1 3
3 4
5 6
1 2
3 5
2 3

Output
1 2 3 4 5 6
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
vector<int> adj[N];
vector<bool> visietd(N, false);
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
    for (int u = 1; u <= n; u++)
    {
        sort(adj[u].begin(), adj[u].end());
    }
}

void dfs(int u) {
    cout << u << ' ';
    visietd[u] = true;
    for (const int &v : adj[u]) // duyệt theo địa chỉ của v, thêm const để đảm bảo không thể thay đổi giá trị của v
    {
        if (!visietd[v]) dfs(v);
    }
    
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    for (int u = 1; u <= n; u++) // Sử dụng vòng lặp để đảm bào rằng kể cả đồ thị không liên thông thì vẫn duyệt được hết đồ thị
    {
        if (!visietd[u]) dfs(u);
    }
    
    return 0;
}