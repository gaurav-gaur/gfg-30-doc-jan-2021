// { Driver Code Starts
//Initial Template for C++

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution
{
public:
    long long smallestpositive(vector<long long> array, int n)
    {
        // code here 

        // Constraints:
        // 1 ≤ N ≤ 10^6
        // 1 ≤ array[i] ≤ 10^9
        // Sum of all elements too won't cause overflow
        // Array may contain duplicates.
        // First of all sort the array
        sort(array.begin(), array.end()); // O(nLogn)

        // Result stores the smallest positive integer
        // that can not be represented as sum of i-1
        long long result = 1;
        for (int i = 0; i < n; i++) { // O(n)
            // Whenever element at ith index is greater than
            // the result, that's the first instance of gap
            // cause result represents first smallest positive 
            // integer that can't be represented, had there be
            // no gap, it could become representable after adding
            // the number at ith position
            // Understandng it by examples
            // if sorted array is [2, 4, 6]
            // Since 2 > result which is 1, the result will be 1
            // If sorted array is [1, 4, 6]
            // This condition will be false which should be the case
            if (array.at(i) > result) {
                return result;
            }
            else
                // if for range 0 to i-1, 
                // The 'result' contains the first value
                // which can't be represented by sum of a permuation
                // that also means numbers from [1, result - 1] 
                // can always be obtained by sum of at least one 
                // permutation from 0 to i-1, that means the next result
                // can easily be obtained by adding a[i] to current result
            {
                result = result + array.at(i);
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
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }
        Solution ob;
        cout << ob.smallestpositive(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends