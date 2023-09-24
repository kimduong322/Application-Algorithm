/*
Problem: Simulation Queue

Description
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
Input
Each line contains a command (operration) of type
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)

Example

Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#

Output
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#

Output
1
NULL
4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   queue<int> qe;
   string cmd;
   int numb;
   do
   {
    cin >> cmd;
    if (cmd == "#") continue;
    if (cmd == "PUSH")
    {
        cin >> numb;
        qe.push(numb);
    }
    if (cmd == "POP")
    {
        if (qe.empty())
        {
            cout <<  "NULL" << endl;
        } else
        {
            int s = qe.front();
            qe.pop();
            cout << s << endl;
        }
    }
   } while (cmd != "#");
   return 0;
}