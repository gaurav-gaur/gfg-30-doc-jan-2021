// { Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends


//User function Template for C++

class Solution {
public:
    bool isBitSet(int n, int pos) {
        return n & (1 << pos);
    }

    long long sumBitDiff(int arr[], int n)
    {
        // constraint: 1 <= arr[i] <= 10^8
        // Let's compute the max number of bits 
        // for the given constraint
        int maxBits = (int)(floor(log2(pow(10, 8)))) + 1;

        // We can also get this number by simple calculations
        //  on paper
        // An inequality to remember for all computer scientists
        // => 2 ^ 10 > 10 ^ 3 (1024 > 1000)
        // => 2 ^ 30 > 10 ^ 9 
        // Divide both sides by 10, so on left side divide with
        // a power of 2 smaller than 10 so that greater than
        // condition holds true if after the division
        // => 2 ^ 27 > 10 ^ 8
        // Hence for the given constraint the number size will 
        // be 27 bits

        // If at any bit position in two numbers' bits
        // are different then they will contribute to 
        // difference of 2 because we are considering
        // (x, y) and (y, x) as two different pairs.

        // So if any position has n 0s and m 1s then 
        // sum of bit difference for that position 
        // would be 2 * n * m;
        // 2 * # set bits * # unset bits

        // Now for all bit positions if we add this, 
        // we'll have sum of bit diff
        int totalBitDiff = 0;
        // b bit position
        for (int b = 0; b < maxBits; b++) {
            int setBitsCount = 0;
            for (int i = 0; i < n; i++) {
                setBitsCount += (isBitSet(arr[i], b) ? 1 : 0);
            }
            totalBitDiff += 2 * (setBitsCount) * (n - setBitsCount);
        }
        return totalBitDiff;
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
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.sumBitDiff(arr, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends