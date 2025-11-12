/*

Implement a problem of maximizing Profit by trading stocks based on 
given rate per day. 
Statement: Given an array arr[] of N positive integers which denotes 
the cost of selling and buying stock on each of the N days. The task is 
to find the maximum profit that can be earned by buying a stock on or 
selling all previously bought stocks on a particular day.

*/

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter number of days: ";
    cin >> N;

    int arr[50];

   
    for (int i = 0; i < N; i++) {
        cout << "Enter price on day " << i + 1 << ": ";
        cin >> arr[i];
    }

    int minPrice = arr[0];  
    int maxProfit = 0;      

    for (int i = 1; i < N; i++) {
        int profit = arr[i] - minPrice;
        if (profit > maxProfit) {
            maxProfit = profit;
        }
        if (arr[i] < minPrice) {
            minPrice = arr[i];
        }
    }

    cout << "Maximum Profit = " << maxProfit << endl;

    return 0;
}

/*

Output:-

PS C:\TY-SEM-I\ADSA LAB> g++ Assignment_No_VI.cpp
PS C:\TY-SEM-I\ADSA LAB> ./a
Enter number of days: 6
Enter price on day 1: 7
Enter price on day 2: 1
Enter price on day 3: 5
Enter price on day 4: 3
Enter price on day 5: 6
Enter price on day 6: 4

Maximum Profit = 5
PS C:\TY-SEM-I\ADSA LAB> 

*/
