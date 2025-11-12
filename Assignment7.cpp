/*
Implement a problem of minimum work to be done per day to CO2 
finish given tasks within D days problem. 
Statement: Given an array task [] of size N denoting amount of work to 
be done for each task, the problem is to find the minimum amount of 
work to be done on each day so that all the tasks can be completed in 
at most D days.
Note: On one day work can be done for only one task.

*/
#include <iostream>
using namespace std;

int main() {
    int N, D;
    cout << "Enter number of tasks: ";  
    cin >> N; 

    cout << "Enter number of days: ";
    cin >> D; 

    int task[50];
    int totalWork = 0;

     for (int i = 0; i < N; i++) {
        cout << "Enter work for task " << i + 1 << ": ";
        cin >> task[i];
        totalWork += task[i];
    }

     int maxTask = task[0];
    for (int i = 1; i < N; i++) {
        if (task[i] > maxTask) {
            maxTask = task[i];
        }
    }

     int avg = totalWork / D;
    if (totalWork % D != 0) {
        avg = avg + 1;  
    }

 
    int minimumWork;
    if (maxTask > avg) {
        minimumWork = maxTask;
    } else {
        minimumWork = avg;
    }

    cout << "Minimum work per day = " << minimumWork << endl;

    return 0;
}

/*

Output:-

PS C:\TY-SEM-I\ADSA LAB> g++ Assignment_No_VII.cpp
PS C:\TY-SEM-I\ADSA LAB> ./a
Enter number of tasks: 5
Enter number of days: 3
Enter work for task 1: 3
Enter work for task 2: 2
Enter work for task 3: 4
Enter work for task 4: 7
Enter work for task 5: 6

Minimum work per day = 8
PS C:\TY-SEM-I\ADSA LAB> 
*/


