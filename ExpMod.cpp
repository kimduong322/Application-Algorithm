/*
Problem: EXPMOD
Description
Given two positive integers a and b. Compute a^b mod (10^9 + 7)
Input
One line contains two integers a and b (1 <= a,b <= 18446744073709551614)
Output
The value a^b mod (10^9+7)
Example
Input
2  3
Output
8
*/

#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull P = 1e9+7;

ull Exp(ull x, ull N) {
    if (N == 1) {
        return x;
    } else {
        x = x % P; // x^N mod P = (x mod P) * (x mod P) * .. *(x mod P)
        ull t = Exp(x, N/2) % P;
        ull res = (t*t) % P;
        if (N % 2 == 1)
        {
            res = (res*x) % P;
        }
        return res;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ull x, N;
    cin >> x >> N;
    cout << Exp(x, N) << endl;
    return 0;
}