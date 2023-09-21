/*
Problem: Largest black subrectangle
Description

Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. 
Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là 
ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
Dữ liệu
· Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
· Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
Kết quả
· Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
Ví dụ
Dữ liệu
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
Kết quả
6
*/

#include<bits/stdc++.h>
using namespace std;

int A[1001][1001];
int n, m;
int histogramOfA[1001];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

int getMaxAreaRetangleOfHistogram(int histogram[], int n) {
    // sử dụng stack để lưu trữ index của các phần tử luôn nhỏ hơn phần tử đang xét
    stack<int> st;
    // Lưu vị trí phần tử nhỏ hơn phần tử hiện tại gần nhất bên trái và bên phải
    vector<int> left_smaller(n, -1), right_smaller(n, n); // right_smaller(n, -1) sẽ ra kết quả sai ở một số trường hợp
    int result;
    st.push(-1);
    int i = 0;
    result = histogram[0];
    while (i < n)
    {
        while (!st.empty() && st.top()!= -1 && histogram[st.top()] > histogram[i])
        {
            right_smaller[st.top()] = i;
            st.pop();
        }
        if (i> 0 && histogram[i] == histogram[i-1])
        {
            left_smaller[i] = left_smaller[i-1];
        }
        else
        {
            left_smaller[i] = st.top();
        }
        st.push(i);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        result = max(result, histogram[i] * (right_smaller[i]-left_smaller[i]-1));
    }
    return result;
}

int solve(int A[1001][1001], int n, int m) {
    int histogram[m];
    int LargestSubRetangle = 0;
    for(int i = 0; i < m; i++) histogram[i] = A[0][i];
    LargestSubRetangle = max(LargestSubRetangle, getMaxAreaRetangleOfHistogram(histogram, m));
    // cout << LargestSubRetangle << endl;
    for (int j = 1; j < n; j++)
    {
        for(int i = 0; i < m; i++) {
            if (A[j][i] == 0)
            {
                histogram[i] = 0;
            } else histogram[i] += 1;
        }
        LargestSubRetangle = max(LargestSubRetangle, getMaxAreaRetangleOfHistogram(histogram, m));
        // cout << LargestSubRetangle << endl;
    }
    return LargestSubRetangle;
}

int main() {
    input();
    // int histogram[] = {6, 2, 5, 4, 5, 1, 6};
    // int N = sizeof(histogram)/sizeof(histogram[0]);
    // cout << getMaxAreaRetangleOfHistogram(histogram, N) << endl;
    cout << solve(A, n, m) << endl;
    return 0;
}