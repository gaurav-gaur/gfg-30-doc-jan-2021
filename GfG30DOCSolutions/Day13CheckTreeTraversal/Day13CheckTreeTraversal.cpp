// { Driver Code Starts
//Initial Template for C++

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <cassert>
using namespace std;


// } Driver Code Ends


//Back-end complete function Template for C++

class Solution {
public:
    struct Node {
        int value; struct Node* left, * right;
        Node(int val) : value(val),
            left(NULL), right(NULL) {}
    };

    int findRightMostIndex(const vector<int>& vec,
        int start, int end, int elem) {
        for (int i = end; i >= start; i--)
            if (vec.at(i) == elem)
                return i;
        return -1;
    }

    Node* buildTreeHelper(const vector<int>& preorder,
        const vector<int> & inorder, int start, int end, int& pIndex) {
        if (start > end)
            return NULL;

        Node* root = new Node(preorder[pIndex++]);

        // In case of duplicate elements, inorder element will be 
        // reversed given that all equal elements are tracked in left 
        // branches
        // Ex;    1
        //      /   \
        //     4'   2
        //    /  \
        //   4''  3 
        // Preorder: 1 4' 4'' 3 2
        // Inorder: 4'' 4' 3 1 2
        // So we can see when will try to find the index of 4' 
        // in in order tree it will be right most 4, which is 4'
        int index = findRightMostIndex(inorder, start, end, root->value);
        if (index == -1) {
            delete root;
            pIndex--;
            return NULL;
        }

        root->left = buildTreeHelper(preorder, inorder, start, index - 1, pIndex);

        root->right = buildTreeHelper(preorder, inorder, index + 1, end, pIndex);

        return root;

    }

    Node* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if (preorder.size() != inorder.size())
            return NULL;

        // pick element from preorder
        // Index of first element of in preorder - the root element
        int pIndex = 0;
        int n = preorder.size();

        return buildTreeHelper(preorder, inorder, 0, n - 1, pIndex);
    }

    void fillPostorder(Node* root, vector<int>& postorder) {
        if (root == NULL) return;
        fillPostorder(root->left, postorder);
        fillPostorder(root->right, postorder);
        postorder.push_back(root->value);
    }

    bool checktree(int preorder[], int inorder[],
        int postorder[], int N)
    {
        // Building tree using preorder and inorder
        Node* root = buildTree(vector<int>(preorder, preorder + N),
            vector<int>(inorder, inorder + N));

        // Compare the 
        vector<int> computedVec;
        computedVec.reserve(N);
        fillPostorder(root, computedVec);
        vector<int> passedVec(postorder, postorder + N);
        return computedVec == passedVec;
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
        int *preorder = new int[n];
        int *inorder = new int[n];
        int *postorder = new int[n];

        for (int i = 0; i < n; ++i)
            cin >> preorder[i];

        for (int i = 0; i < n; ++i)
            cin >> inorder[i];

        for (int i = 0; i < n; ++i)
            cin >> postorder[i];

        Solution obj;
        if (obj.checktree(preorder, inorder, postorder, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

// } Driver Code Ends