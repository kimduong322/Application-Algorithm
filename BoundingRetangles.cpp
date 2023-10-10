/*
Problem: Bounding rectangle
Description
Cho một danh sách các hình chữ nhật 1, 2,…, n. Hãy tìm diện tích hình chữ nhật nhỏ nhất 
bao tất cả các hình chữ nhật trong danh sách trên
Dữ liệu
· Dòng 1: chứa số nguyên dương n (1 <= n <= 1000)
· Dòng i+1 (i=1,…,n): chứa 4 số nguyên dương x1,y1, x2,y2 trong đó (x1,y1) và (x2,y2) 
là tọa độ 2 đỉnh đối của hình chữ nhật thứ i (1 <= x1, y1, x2, y2 <= 100)
Kết quả
· Ghi ra diện tích của hình chữ nhật nhỏ nhất tìm được
Ví dụ
Dữ liệu
3
2 4 2 7
3 2 4 7
1 2 5 2
Kết quả
20
*/

#include<bits/stdc++.h>
using namespace std;

int leftRetangle = INT_MAX, rightRetangle=-INT_MAX;
int topRetangle=-INT_MAX, bottomRetangle=INT_MAX;
int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    int x1, y1, x2, y2;
    for (int  i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        leftRetangle = min(leftRetangle, x1); leftRetangle = min(leftRetangle, x2);
        bottomRetangle = min(bottomRetangle, y1); bottomRetangle = min(bottomRetangle, y2);
        rightRetangle = max(rightRetangle, x1); rightRetangle = max(rightRetangle, x2);
        topRetangle = max(topRetangle, y1); topRetangle = max(topRetangle, y2);
    }
    cout << (rightRetangle-leftRetangle) * (topRetangle-bottomRetangle) << endl;
    return 0;
}