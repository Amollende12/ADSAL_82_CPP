/*Implement Subset Sum Problem. Statement:-Given a set of nonnegative integers and a value sum, the task is to check if there is a 
subset of the given set whose sum is equal to the given sum.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    int sum;
    cout << "Enter sum to check: ";
    cin >> sum;

     bool dp[101][101] = {false};

     for (int i = 0; i <= n; i++)
        dp[i][0] = true;

 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] > j)   
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

     
    if (dp[n][sum])
        cout << "Subset with given sum exists.";
    else
        cout << "No subset with given sum exists.";

    return 0;
}

/*Output:-
Enter Number Of elements:-10
Enter Element:8
6
8
5
8
4
5
6
5
10
15
75

*/
