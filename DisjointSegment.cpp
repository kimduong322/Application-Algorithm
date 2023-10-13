/*
Problem: Disjoint Segment
Description
Given a set of segments X = {(a_1, b_1),.., (a_n, b_n)} in which a_i < b_i are coordinates 
of the segment i on a line, i = 1, …, n.  Find a subset of X having largest cardinality in 
which no two segments of the subset intersect.
Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line i+1 (i= 1,...,n): contains ai and bi (0 <= a_i <= b_i <= 1000000)
Output
Number of segments in the solution found.
Example
Input
6
0 10
3 7
6 14
9 11
12 15
17 19

Output
4
*/

#include<bits/stdc++.h>
using namespace std;

struct compareSegment
{
    bool operator()(pair<int, int> segment1, pair<int, int> segment2) const {
        return segment1.second <= segment2.second;
    }
};
set<pair<int, int>, compareSegment> segments;
int n;
int res; // number of disjoint segment
int l; //lastest-segment.second

void input() {
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        segments.insert(make_pair(a, b));
    }
    
    // for (const pair<int, int> segment : segments)
    // {
    //     cout << segment.first << ", " << segment.second << endl;
    // }
}

void solve() {
    /*
        res = 1;
        l = segments.begin.second
        segments remove first
        duyệt các phần tử segment còn lại trong segment
            Nếu segment.first >= l thì
                res++
                l = segment.second
    */
    res = 0;
    l = -1; // Initial value for the last segment end

    while (!segments.empty()) {
        auto it = segments.begin();
        pair<int, int> currentSegment = *it;

        if (currentSegment.first > l) { // không được xét điều kiện currentSegment.first >= l, bởi như vậy hai đoạn đã giao nhau tại vị trí điểm l rồi
            res++;
            l = currentSegment.second;
        }

        segments.erase(it);
    }
}

int main() {
    input();
    solve();
    cout << res << endl;
    return 0;
}