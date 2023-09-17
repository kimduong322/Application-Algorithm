#include <bits/stdc++.h>
using namespace std;

int A[1000][1000];
int d[1000][1000];
int n, m, r, c;

void input() {
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }
    
}

int main() {
    input();
    typedef pair<int, int> ii;
    queue<ii> qe; // queue elements

    int dr[] = {0, 1, 0, -1};
    int dc[] = {-1, 0, 1, 0};
    int result = -1;

    qe.push(ii(r, c));
    A[r][c] = 1;
    d[r][c] = 0;

    while (!qe.empty())
    {
        ii u = qe.front();
        qe.pop();
        for (int k = 0; k < 4; k++)
        {
            int r = u.first + dr[k];
            int c = u.second + dc[k];
            if (r < 1 || c < 1 || r > n || c > m)
            {
                result = d[u.first][u.second] + 1;
                break;
            }
            else if (A[r][c] != 1)
            {
                qe.push(ii(r, c));
                d[r][c] = d[u.first][u.second] + 1;
                A[r][c] = 1;
            }
            
        }
        if (result != -1) {
                break;
        }
        
    }
    
    cout << result << endl;
    
    return 0;
}