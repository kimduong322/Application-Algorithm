/*
Problem: Balanced Courses Assignments
Description
At the beginning of the semester, the head of a computer science department D have to 
assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m}
and n courses C={1,2,...,n}. Each teacher t∈T has a preference list which is a list of 
courses he/she can teach depending on his/her specialization. We known a list of pairs of 
conflicting two courses that cannot be assigned to the same teacher as these courses have 
been already scheduled in the same slot of the timetable. The load of a teacher is the number
of courses assigned to her/him. How to assign nn courses to mm teacher such that each course
assigned to a teacher is in his/her preference list, no two conflicting courses are assigned
to the same teacher, and the maximal load is minimal.
Input
The input consists of following lines
Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
Line i+1: contains an positive integer k and k positive integers indicating the courses 
that teacher i can teach (∀i=1,…,m)
Line m+2: contains an integer k
Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
Output
The output contains a unique number which is the maximal load of the teachers in the solution 
found and the value -1 if not solution found.
Example
Input
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12

Output
3
*/

#include<bits/stdc++.h>
using namespace std;
int m, n;
int maxLoad = INT_MAX; // find min of maxLoad
int referenceCourseOfTeachers[12][32];
int conflictingCourseOfCourse[32][500];
int teacherOfCourse[32];
int load[12];

bool inReferenceCourseOf(int teacherNumb, int courseNumb) {
    bool check = false;
    for (int i = 1; i <= 30 && referenceCourseOfTeachers[teacherNumb][i] != 0; i++) {
        if (referenceCourseOfTeachers[teacherNumb][i] == courseNumb) {
            check = true;
            break;
        }
    }
    return check;
}

bool conflicted(int teacherNumb, int courseNumb) {
    bool check = false;
    // get all assigned course of teacher with teacherNumb
    vector<int> assignedCourse;
    for (int i = 1; i <= courseNumb; i++)
    {
        if (teacherOfCourse[i] == teacherNumb) {assignedCourse.push_back(i);}
    }
    for (unsigned int i = 0; i < assignedCourse.size(); i++)
    {
        int c = assignedCourse[i];
        for (int j = 0; j < 436 && conflictingCourseOfCourse[c][j] != 0; j++)
        {
            if (conflictingCourseOfCourse[c][j] == courseNumb) {
                check = true;
                break;
            }
        }
        if (check == true) break;
    }
    return check;
}

bool isCanAssignTeacher(int course, int teacher) {
    if (!inReferenceCourseOf(teacher, course)) return false;
    else if (conflicted(teacher, course)) return false;
    return true;
}

void printSol() {
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", teacherOfCourse[i]);
    }
    printf("\n");
}

void Try(int course) {
    for (int teacher = 1; teacher <= m; teacher++)
    {
        if (isCanAssignTeacher(course, teacher)) {
            teacherOfCourse[course] = teacher;
            load[teacher]++;
            if (course == n)
            {
                int maxLoadOfCurrentSolution = -INT_MAX; // find max
                for(int i = 1; i <= m; i++) {maxLoadOfCurrentSolution = max(maxLoadOfCurrentSolution, load[i]);}
                maxLoad = min(maxLoad, maxLoadOfCurrentSolution);
                // printSol();
            } else if(load[teacher] < maxLoad) Try(course+1);
            load[teacher]--;
        }
    }
}

int main() {
    
    cin >> m >> n;
    int k;
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> referenceCourseOfTeachers[i][j];
        }
    }
    cin >> k;
    int a, b;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        int len_a = 0;
        while (conflictingCourseOfCourse[a][len_a] != 0) {
            len_a++;
        }
        conflictingCourseOfCourse[a][len_a] = b;
        int len_b = 0;
        while (conflictingCourseOfCourse[b][len_b] != 0) {
            len_b++;
        }
        conflictingCourseOfCourse[b][len_b] = a;
    }
    
    Try(1);
    cout << maxLoad << endl;
    return 0;
}