/*
Problem: Add two integers

Description
Compute the sum of two integers a and b.
Input
Line 1 contains two integers a and b (0 <= a, b <= 10^19)
Ouput
Write the sum of a and b
Example
Input
3 5
Output
8
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    int carry = 0;
    
    int l1 = a.length(), l2 = b.length();
    // b lớn hơn
    if (l1 > l2)
    {
        swap(a, b);
    }
    stack<int> result;
    int indexOfb = l2;
    for (int i = l1-1; i >= 0; i--)
    {
        indexOfb--;
        int sumOfDigit = (a[i]-'0') + (b[indexOfb]-'0') + carry;
        result.push(sumOfDigit % 10);
        carry = sumOfDigit / 10;
    }
    if (indexOfb == 0)
    {
        if (carry > 0) result.push(carry);
    } else
    {
        for (int j = indexOfb-1; j >= 0; j--)
        {
            int sum = (b[j]-'0') + carry;
            result.push(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0) result.push(carry);
    }

    while (!result.empty())
    {
        printf("%d",result.top());
        result.pop();
    }
    
    return 0;
}