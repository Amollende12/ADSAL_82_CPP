/*Kth largest element in an array.
To find the kth largest element using recursive partitioning.... */

#include <iostream>
using namespace std;

// Merge two sorted halves
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] >= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to find kth largest
int findKthLargest(int arr[], int n, int k)
{
    mergeSort(arr, 0, n - 1);
    return arr[k - 1];
}

int main()
{
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid k value" << endl;
        return 0;
    }

    int result = findKthLargest(arr, n, k);
    cout << k << "th largest element is: " << result << endl;

    return 0;
}

//INPUT:-arr[6]={3,2,1,5,6,4}, k=2
//OUTPUT:- 2th largest element is: 5
