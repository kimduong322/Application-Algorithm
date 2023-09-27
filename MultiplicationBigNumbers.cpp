/*
Problem: Multiplication of Big numbers
Description
Cho hai số nguyên dương a và b rất lớn (số chữ số có thể lên tới 10000). Hãy tính và in ra tích của 2 số đó.
Input
Dòng 1: ghi số a
Dòng 2: ghi số b
Output
Ghi kết quả a*b

Example
Input
123
654

Output
80442

Example
Input
100000000000000000
123456789
Output
12345678900000000000000000
*/

#include <bits/stdc++.h>
using namespace std;
string numb1, numb2;

string solve() { // n1 * n2

    int l1 = numb1.length(), l2 = numb2.length();
    vector<int> result(l1+l2, 0);
    int i_n1 = 0, i_n2 = 0;

    for (int i = l2-1; i >= 0 ; i--) {
        // Lay tung ki tu cua numb2 * numb1
        i_n1 = 0;
        int digit_from_numb2 = numb2[i] - '0';
        int carry = 0;
        // duyet qua tat ca cac ki tu cua numb1
        for (int j = l1-1; j >= 0; j--)
        {
            int digit_from_numb1 = numb1[j] - '0';
            int sum = digit_from_numb2 * digit_from_numb1 + carry + result[i_n2 + i_n1];
            
            result[i_n2 + i_n1] = sum % 10;
            carry = sum / 10;

            i_n1++;
        }
        if (carry > 0) result[i_n2 + i_n1] += carry;
        // dịch chuyển cho số 2
        i_n2++;
    }

    // in ket qua duoi dang chuoi
    int index = result.size() - 1;
    while(index >= 0 && result[index] == 0) index--;
    if (index == -1) return "0";  // numb1 == 0 || numb2 == 0
    string s = "";
    while(index >= 0) {
        s += to_string(result[index]);
        index -= 1;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> numb1;
    cin >> numb2;

    cout << solve() << endl;
    return 0;
}