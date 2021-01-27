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
    // Time Complexity: O(n), space complexity O(n)
    void prank(long long a[], int n) {
        // code here
        // element index map
        unordered_map<int, int> a_i;
        // fill element index map
        for (int i = 0; i < n; i++) {
            a_i[a[i]] = i;
        }
        // to keep things simple, use a temp array
        int* b = new int[n];  
        // core shuffle logic
        for (int i = 0; i < n; i++) {
            // a_i[i] will give position at which
            // roll number i is placed, then
            // place a[i] i.e. current element at
            // that place.
            b[a_i[i]] = a[i];
        }
        // copy elements in original array
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }

    //void swapOneLoop(long long a[], int n, int index) {
    //    int startIndex = index;
    //    long long startIndexValue = a[index];
    //    do {
    //        int nextIndex = (int)a[index];
    //        if (nextIndex == startIndex) {
    //            a[index] = startIndexValue;
    //        }
    //        else {
    //            a[index] = a[nextIndex];
    //        }
    //        index = nextIndex;
    //    } while (index != startIndex);
    //}

    //// Time complexity: O(n), Auxiliary Space: O(1)
    //void prank(long long a[], int n) {
    //    assert(n > 0);


    //}
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