// { Driver Code Starts
#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

// } Driver Code Ends


class Solution {

public:
    // Sum of a given column in sub matrix
    // Ex:
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // for top left index 0, 0 and k=2
    // column sum = mat[0][0] + mat[1][0] = ;
    int colSum(const vector<vector<int> >& mat, int row, int col, int K) {
        int colSum = 0;
        for (int i = row; i < row + K; i++) {
            colSum += mat[i][col];
        }
        return colSum;
    }

    int Maximum_Sum(vector<vector<int> >& mat, int N, int K) {
        // Your code goes here
        assert(N >= K);
        // In order to avoid calculating same cells again and again
        // we'll use rolling sum technique
        // For that we need to preprocess the sum of vertical strips
        // of height K and width 1
        vector<vector<int> > kMat(N-K+1);
        // Number of rows will be N - K + 1, Number of cols will be N
        for (int i = 0; i < N - K + 1; i++) {
            kMat[i] = vector<int>(N);
        }
        
        for (int i = 0; i < N - K + 1; i++) {
            for (int j = 0; j < N; j++) {
                kMat[i][j] = colSum(mat, i, j, K);
            }
        }

        int maxSubMatSum = -INT_MIN;

        for (int i = 0; i < N - K + 1; i++) {
            int currSubMatSum = 0;
            for (int j = 0; j < K; j++) {
                currSubMatSum += kMat[i][j];
            }
            if (currSubMatSum > maxSubMatSum) {
                maxSubMatSum = currSubMatSum;
            }
            for (int j = 1; j < N - K + 1; j++) {
                currSubMatSum = currSubMatSum + kMat[i][j + K - 1] - kMat[i][j-1];
                if (currSubMatSum > maxSubMatSum) {
                    maxSubMatSum = currSubMatSum;
                }
            }
        }
        return maxSubMatSum;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mat[i][j];
            }
        }

        int k; cin >> k;
        Solution obj;
        cout << obj.Maximum_Sum(mat, N, k) << "\n";
    }

    return 0;
}
// } Driver Code Ends