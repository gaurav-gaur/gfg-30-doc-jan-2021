// { Driver Code Starts
//Initial template for C++

#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution {
public:
    // Time complexity: O(n), Auxiliary Space: O(1)
    void prank(long long a[], int n) {
        assert(n > 0);
        
        // So here in simple terms we are saying
        // that at any given position whatever roll no
        // is stored, value of roll no at that index 
        // should be copied to it
        // i - position to be updated
        // a[i] - current roll no at i
        // a[a[i]] - element at position a[i]
        
        // Now the problem is if we update
        // a[i] = a[a[i]] we lose the value at a[i]
        // So that whenever we have to updates the position
        // whose value is i, then we'll not have original a[i]
        // as that has already been over written

        // To solve that whatever value we are trying to store at where a
        // is stored , we'll store along with value of a, so that we don't lose it
        // a + b * n


        // in scenario where 
        // a should get b, and c should get a        
        // At a's place, store a + (b % n) * n
        // At c's place, store c + (a + (b % n) * n)%n*n => c + (a % n)*n
        // because ((b % n)*n)%n will be 0

        // so to just get b at a, and a at c, if we divide everything by n
        // then a / n -> 0 because a lies between 0 to n-1 and only b remain there, 
        // and b will be stored at a
        // similary it will work for a at c.
        // Putting it all together
        for (int i = 0; i < n; i++) {
            a[i] += (a[a[i]] % n) * n;
        }

        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long *a = new long long[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        ob.prank(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}

// } Driver Code Ends