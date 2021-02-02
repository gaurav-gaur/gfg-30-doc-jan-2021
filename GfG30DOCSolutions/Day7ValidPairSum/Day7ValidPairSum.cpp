// { Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <algorithm>
using namespace std;

// } Driver Code Ends


//User function Template for C++


class Solution {

public:

    long long ValidPair(int a[], int n)
    {
        // Your code goes here 
        long long result = 0;

        // If n is less than 2, then there can't be any pairs
        if (n < 2) {
            return result;
        }
        // Sort the array
        sort(a, a + n);

        // We need not consider the last element as that has already been considered
        for (int i = 0; i < n - 1; i++) {
            // Considering case of negative and positive elements separately
            // Because in case of negative element, second value of the first
            // pair which adds up to value greater than 0, may be different
            // for each negative element, and all the elements towards right
            // of that first match will result in a pair which will be having
            // positive sum
            if (a[i] <= 0) {
                // If pair {a[i], a[j]}, we have to find out j such that
                // a[i] + a[j] > 0
                // if a[j] = k, then k = -a[i] + 1;
                // ki - index of k, so j = *ki;
                // Ex: 
                // -4 0 3 6 7 
                // for a[i] = 4, k = 5, ki will be pointer to 6
                // so possible pairs will be (-4, 6) and (-4, 7) 
                int k = -a[i] + 1;
                // Find out the first value which is equal to or greater than k
                int *ki = lower_bound(a, a + n, k);
                // If there is no value which is equal to or greater than k in range
                // then ki will a + n
                if (ki != a + n) {
                    result += (a + n - ki); // number of possible pairs
                }
            }
            
            // if a[i] > 0, then there can be slight optimization further by 
            // computing all the values in one shot instead of computing them
            // for each element
            if (a[i] > 0) {
                // 1 2 3 4
                // so at i = 0, we have a situation that all the elements in
                // right side will make up a valid pair
                // so total such pair will be sum of natural numbers
                // for n - i - 1 elements
                result += (n - i) * (n - i - 1) / 2;
                break;
            }
        }

        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *array = new int[n];
        for (int i = 0; i < n; ++i)
            cin >> array[i];
        Solution obj;
        cout << obj.ValidPair(array, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends