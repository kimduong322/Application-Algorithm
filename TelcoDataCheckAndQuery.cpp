/*
Description

Write a C program to perform some queries on a telco data (comming from stdin) 
with the following format:
The first block of data consists of lines (terminated by a line containing #), 
each line (number of lines can be up to 100000) is under the form: 
        call <from_number> <to_number> <date> <from_time> <end_time> 
which is a call from the phone number <from_number> to a phone number 
<to_number> on <date>, and starting at time-point <from_time>, terminating at 
time-point <end_time>

<from_number> and <to_number> are string of 10 characters (a phone number is 
correct if it contains only digits 0,1,...,9, otherwise, the phone number is 
incorrect)
<date> is under the form YYYY-MM-DD (for example 2022-10-21)
<from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)
 
The second block consists of queries (terminated by a line containing #), each 
query in a line (number of lines can be up to 100000) and belongs to one of the 
following types:

?check_phone_number: print to stdout (in a new line) value 1 if no phone number 
is incorrect
?number_calls_from <phone_number>: print to stdout (in a new line) the number of 
times a call is made from <phone_number>
?number_total_calls: print to stdout (in a new line) the total number of calls 
of the data
?count_time_calls_from <phone_number>: print to stdout (in a new line) the total 
time duration (in seconds) the calls are made from <phone_number>

Example
Input
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#
*/

#include<bits/stdc++.h>
using namespace std;


bool isIncorrectPhone(string phoneNumer) {
    if(phoneNumer.length() != 10) return true;
    for (int i = 0; i < 10; i++)
    {
        if(!(phoneNumer[i] >= '0' && phoneNumer[i] <= '9')) return true;
    }
    return false;
}

// ftime, etime has format hh:mm:ss
int countTime(string ftime, string etime) {
    int startTime = 3600 * ((ftime[0]-'0')*10 + (ftime[1]-'0'))
                    + 60 * ((ftime[3]-'0')*10 + (ftime[4]-'0'))
                     + 1 * ((ftime[6]-'0')*10 + (ftime[7]-'0'));
    int endTime   = 3600 * ((etime[0]-'0')*10 + (etime[1]-'0'))
                    + 60 * ((etime[3]-'0')*10 + (etime[4]-'0'))
                     + 1 * ((etime[6]-'0')*10 + (etime[7]-'0'));

    return endTime - startTime;
}

void TelcoDataCheckAndQueryUsingCinForUserInput() {
    unordered_map<string, int> numberCalls, timeCall;
    int incorrectPhones = 0;
    int nbTotalCalls = 0;
    string type;
    string fPhoneNumber, toPhoneNumber, day, ftime, etime;
    do
    {
        cin >> type;
        if (type == "#") continue;
        if (type == "call")
        {
            cin >> fPhoneNumber >> toPhoneNumber >> day >> ftime >> etime;
            ++nbTotalCalls;
            if (isIncorrectPhone(fPhoneNumber) || isIncorrectPhone(toPhoneNumber))
            {
                incorrectPhones++;
            }
            numberCalls[fPhoneNumber]++;
            timeCall[fPhoneNumber] += countTime(ftime, etime);
            
        }
    } while (type != "#");

    do
    {
        string numberForQuery;
        cin >> type;
        if (type == "#") continue;
        if (type == "?check_phone_number")
        {
            if(incorrectPhones == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        if (type == "?number_calls_from")
        {
            cin >> numberForQuery;
            cout << numberCalls[numberForQuery] << endl;
        }
        if (type == "?number_total_calls")
        {
            cout << nbTotalCalls << endl;
        }
        if (type == "?count_time_calls_from")
        {
            cin >> numberForQuery;
            cout << timeCall[numberForQuery] << endl;
        }
        
    } while (type != "#");
    
}

void TelcoDataCheckAndQueryUsingScanfForUserInput() {
    unordered_map<string, pair<int, int>> phoneData; //pair.first = number_calls_from <string>; pair.second = count_time_calls_from <string>
    char type[23];
    char fromNumb[11], toNumb[11], date[11], ftime[9], etime[9];
    int incorrectPhones = 0;
    int nbTotalCalls = 0;
    do
    {
        scanf("%s", type);
        if (strcmp(type, "#") == 0)
        {
            continue;
        }
        if (strcmp(type, "call") == 0)
        {
            scanf("%s %s %s %s %s", fromNumb, toNumb, date, ftime, etime);
            if (isIncorrectPhone(fromNumb) || isIncorrectPhone(toNumb))
            {
                incorrectPhones++;
            } else
            {
                nbTotalCalls ++;
                if (phoneData.find(fromNumb) == phoneData.end())
                {
                    phoneData[fromNumb] = {0, 0};
                }
                phoneData[fromNumb].first += 1;
                phoneData[fromNumb].second += countTime(ftime, etime);
            }
        }
    } while (strcmp(type, "#") != 0);
    
    char k[11];
    do
    {
        scanf("%s", type);
        if (strcmp(type, "#") == 0)
        {
            continue;
        }
        if (strcmp(type, "?check_phone_number") == 0)
        {
            printf("%d\n", incorrectPhones == 0 ? 1 : 0);
        } else if (strcmp(type, "?number_calls_from") == 0)
        {
            scanf("%s", k);
            printf("%d\n", phoneData[k].first);
        } else if (strcmp(type, "?number_total_calls") == 0)
        {
            printf("%d\n", nbTotalCalls);
        } else if (strcmp(type, "?count_time_calls_from") == 0)
        {
            scanf("%s", k);
            printf("%d\n", phoneData[k].second);
        }
    } while (strcmp(type, "#") != 0);
}

int main() {
    /*
    this version of code has performance problem when user input data volume is large
    cin slower than scanf => using scanf can improve performance
    */
    // TelcoDataCheckAndQueryUsingCinForUserInput();
    TelcoDataCheckAndQueryUsingScanfForUserInput();
    return 0;
}