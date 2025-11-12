/*Implement Coin Change problem. Statement: - Given an integer array
of coins [] of size N representing different types of currency and an
integer sum, The task is to find the number of ways to make sum by
using different combinations from coins[]*/
#include <iostream>
using namespace std; 

int main() {
    int N, sum;
    cout << "Enter number of coins: ";
    cin >> N;
    int coins[N];
    cout << "Enter coin values: ";
    for(int i=0;i<N;i++){
        cin>>coins[i];
    }

    cout<<"Enter the sum:- ";
    cin>>sum;

    int dp[100] = {0};
    dp[0] = 1;

    for (int i=0;i<N;i++) {
    for (int j=coins[i];j<=sum;j++) {
        dp[j]+=dp[j-coins[i]];
    }
}   

  cout<<"Number of ways to make sum = "<<dp[sum]<<endl;
    
    return 0;
}

/*INPUT:-Enter number of coins: 4
Enter coin values: 2
5
10
20
Enter the sum:- 55*/

//OUTPUT:- Number of ways to make sum = 34
