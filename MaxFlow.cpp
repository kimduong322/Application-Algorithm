#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int fordFulkerson(vector<vector<int>> &graph, int source, int sink)
{
    int n = graph.size();
    vector<vector<int>> residualGraph(graph);

    vector<int> parent(n, -1);
    int maxFlow = 0;

    while (true)
    {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v)
            {
                if (!visited[v] && residualGraph[u][v] > 0)
                {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }

        if (!visited[sink])
        {
            break; // No augmenting path found
        }

        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    int s, t;
    cin >> s >> t;

    for (int i = 1; i <= M; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = c;
    }

    int maxFlow = fordFulkerson(graph, s, t);
    cout << maxFlow << endl;

    return 0;
}
