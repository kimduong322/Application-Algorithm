#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int n, a[MAXN];
int mem[MAXN];
int pos = -1;

int dp (int i) {

    if (mem[i] != -1) return mem[i];
    int res = 1;
    for (int j = 1; j < i; j++) {
        if (a[j] < a[i]) res = max(res, 1 + dp(j));
    }
    return mem[i] = res;
}

int solve() {
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ans < dp(i)) {
            ans = dp(i);
            pos = i;
        }
    }
    return ans;
}

void trace(int i) {
    for (int j = 0; j < i; j++)
    {
        if (mem[i] == 1 + mem[j] && a[j] < a[i]) {
            trace(j);
            break;
        }
    }
    cout << a[i] << ' ';
    
}

void interative_trace() {

}

int main() {
    memset(mem, -1, sizeof(mem));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cin >> a[i];
    }
    cout << solve() << endl;
    trace(pos);
    return 0;
}