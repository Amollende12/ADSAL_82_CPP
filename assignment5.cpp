/*Implement a problem of activity selection problem with K persons.
Statement: Given two arrays S[] and E[] of size N denoting starting and
closing time of the shops and an integer value K denoting the number
of people, the task is to find out the maximum number of shops they
can visit in total if they visit each shop optimally based on the following
conditions:
 A shop can be visited by only one person.
 A person cannot visit another shop if its timing collides with it.*/

#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter number of shops: ";
    cin >> n;

    int S[n], E[n];
    cout << "Enter start times: ";
    for (int i = 0; i < n; i++)
        cin >> S[i];

    cout << "Enter end times: ";
    for (int i = 0; i < n; i++)
        cin >> E[i];

    cout << "Enter number of persons: ";
    cin >> k;

    // Sorting by end time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (E[i] > E[j])
            {
                swap(E[i], E[j]);
                swap(S[i], S[j]);
            }
        }
    }

    bool visited[n] = {false};
    int count = 0;

    // Greedy approach
    for (int p = 0; p < k; p++)
    {
        int lastE = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && S[i] >= lastE)
            {
                visited[i] = true;
                lastE = E[i];
                count++;
            }
        }
    }

    cout << "Maximum shops visited: " << count << endl;
    return 0;
}

/*INPUT:-S[5]={3,1,3,2,6};
        E[5]={4,10,6.5.9};
        Enter number of persons[k]: 2
         
   OUTPUT:-Maximum shops visited: 3
*/
