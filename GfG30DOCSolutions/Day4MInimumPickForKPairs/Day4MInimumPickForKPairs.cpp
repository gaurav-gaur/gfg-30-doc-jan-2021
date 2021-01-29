// { Driver Code Starts
// Initial Template for C++

#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// } Driver Code Ends


class Solution {

public:
    int find_min(int a[], int n, int k) {
        // Algorithm
        // It may haappen that initially 1 socks is picked from each bucket
        int result = 0;
        for (int i = 0; i < n; i++) {
            a[i]--;
            result++;
        }
        // Now pick a pair until all k pairs are picked
        int remaining = k;
        for (int i = 0; i < n; i++) {
            if (remaining > 0) {
                if (a[i] / 2 > 0) {
                    int possiblePairs = min(remaining, a[i] / 2);
                    a[i] -= possiblePairs * 2;
                    result += possiblePairs * 2;
                    remaining -= possiblePairs;
                }
            }
            else {
                break;
            }
        }
       
        assert(remaining >= 0);
        // If by now, remaining is 0, then we have picked 1 extra
        if (remaining == 0) {
            result--;
            return result;
        }
        else {
            // at this point in time only 1s will be there if any
            // every pick of 1 will make it a pair because in first iteration
            // we picked 1 element from each
            for (int i = 0; i < n; i++) {
                if (remaining > 0) {
                    assert(a[i] == 0 || a[i] == 1);
                    if (a[i] == 1) {
                        result++;
                        remaining--;
                    }
                }
                else {
                    break;
                }
            }
            // Despite of going through all the 1s, still there is remaining pairs
            if (remaining == 0) {
                return result;
            }
            else {
                return -1;
            }
        }
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n;
        int* a = new int[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cin >> k;
        Solution obj;
        cout << obj.find_min(a, n, k) << endl;
    }
    return 1;
}
// } Driver Code Ends