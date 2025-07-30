/*Implement a problem of number of zero 
Given an array of one's and zero's which has all 1st follwed by all 0's ?
find the number of 0's count the number of zeros in the given array.*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr;
    int ch = 1;
    int flag = 0;
    int num;

    while (ch == 1) {
        cout << "Enter number (0 or 1): ";
        cin >> num;

        if (num == 0) {
            flag = 1;
            arr.push_back(num);
        }
        else if (flag == 1 && num == 1) {
            cout << "Invalid input: No 1 is allowed after 0." << endl;
        }
        else if (num == 1) {
            arr.push_back(num);
        }
        else {
            cout << "Only 0 and 1 are allowed." << endl;
        }

        cout << "Want to add more? (1 for Yes / 0 for No): ";
        cin >> ch;
    }

    // Count number of 0's in array
    int count_zero = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0)
            count_zero++;
    }

    cout << "\nFinal Array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << "\nTotal number of 0's: " << count_zero << endl;

    return 0;
}

//INPUT:-int arr[] = {1, 1, 1, 0, 0};
//OUTPUT:-Number of 0s: 2
