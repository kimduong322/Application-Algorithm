/*
Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) 
sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_set<int> seen;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int z = M - a[i];
        if (seen.find(z) != seen.end())
        {
            ++count;
        }
        seen.insert(a[i]);
    }
    cout << count;
    return 0;
}