// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;

// } Driver Code Ends



class Solution {

public:
    int maxCandy(int height[], int n)
    {
        // Your code goes here
        int maxCandies = 0;

        // To solve it in O(n)
        // Let's maximize on width to start with and 
        // optimize for heights, for that let's select
        // the starting left and right books at the end
        int start = 0, end = n - 1;

        while (start < end) {
            int candies = min(height[start], height[end]) * 
                          (end - start - 1);
            if (candies > maxCandies) {
                maxCandies = candies;
            }

            // whichever height is smaller we want to update
            // the index of that, to find a bigger value of 
            // area
            if (height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
        }

        return maxCandies;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *height = new int[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> height[i];
        }

        Solution obj;

        cout << obj.maxCandy(height, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends