// { Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


// } Driver Code Ends


//User function Template for C++

class Solution {

public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        /* The below patterns captures all the edge 
           conditions (I hope so!)
           Input: 3 8 9 5 2 3 4 5 1 5 1
           Output:2 5 5 2 1 1 1 1 -1 1 -1
        */
        stack<int> biggies;
        // modified cells should not be touched example
        // 3 8 9 5 2
        // changes to 3 5 5
        // but when 2 starts replacing bigger elements
        // on left, we should ignored index 2 and 3
        // so for tracking such cells this has been used
        vector<bool> modified(n, false);
        // Let's keep 1 element in stack on which we could
        // hang on to, through out hardships, our support!
        biggies.push(arr[0]);
        for (int i = 1; i < n; i++) {
            // bigger than biggest, go to biggies stack
            if (arr[i] >= biggies.top()) {
                biggies.push(arr[i]);
            }
            // Time to work work
            else {
                int j = i - 1;
                int smallest = arr[i];
                while (!biggies.empty()) {
                    // it may happen that all biggies get replaced
                    // so checking for non emptiness is must
                    if (!biggies.empty() && smallest < biggies.top()) {
                        if (modified[j]) {
                            // already replaced before, so just
                            // Mr j will go one step back
                            j--;
                        }
                        else {
                            // Actual work is happening here
                            // But we need code fort to protect 
                            // it solid code man!
                            arr[j] = smallest;
                            modified[j] = true;
                            biggies.pop();
                            j--;
                        }
                    }
                    else {
                        // Support gone, so put it back!
                        biggies.push(smallest);
                        break;
                    }
                }
                if (biggies.empty()) {
                    // Game is not yet over so, support
                    // should be there
                    biggies.push(smallest);
                }
            }
        }

        // Oh! man elements in array are over,
        // but what these biggies doing in this stack here
        // You all can go home with -1s, Thank you!
        int k = n - 1;
        while (!biggies.empty()) {
            if (modified[k]) {
                k--;
            }
            else {
                arr[k] = -1;
                biggies.pop();
                k--;
            }
        }
        return arr;
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
        vector<int> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array[i];
        }
        Solution obj;
        vector<int> result = obj.help_classmate(array, n);
        for (int i = 0; i < n; ++i)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends