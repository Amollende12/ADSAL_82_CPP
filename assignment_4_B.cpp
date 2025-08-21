/*Count Inversions
Count pairs (i<j) where arr[i]>arr[j] using merge based approach..
*/

#include <iostream>
using namespace std;

// Merge two halves and count inversions
int mergeAndCount(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int invCount = 0;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
            invCount += (n1 - i); // Count inversions
        }
    }

    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];

    return invCount;
}

// Merge Sort to count inversions
int mergeSortAndCount(int arr[], int left, int right)
{
    int invCount = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, left, mid);
        invCount += mergeSortAndCount(arr, mid + 1, right);
        invCount += mergeAndCount(arr, left, mid, right);
    }
    return invCount;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int inversions = mergeSortAndCount(arr, 0, n - 1);
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}

//INPUT:-arr[5]={2,4,1,3,5};
//OUTPUT:-3
