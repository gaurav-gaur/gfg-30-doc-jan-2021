// { Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string Reduced_String(int k, string s) {
        // Your code goes here
        stack<char> st;
        char lastChar = -1;
        int lastCharCount = 0;

        for (size_t i = 0; i < s.length(); i++) {
            if (lastCharCount < k) {
                st.push(s[i]);
                if (s[i] == lastChar) {
                    lastCharCount++;
                }
                else {
                    lastChar = s[i];
                    lastCharCount = 1;
                }
                if (lastCharCount == k) {
                    while (lastCharCount > 0) {
                        st.pop();
                        lastCharCount--;
                    }
                    if (!st.empty()) {
                        lastChar = st.top();
                        lastCharCount = 1;
                        st.pop();
                        while (!st.empty()) {
                            if (lastChar == st.top()) {
                                lastCharCount++;
                                st.pop();
                            }
                            else {
                                break;
                            }
                        }
                        int pushBackCount = 0;
                        while (pushBackCount < lastCharCount) {
                            st.push(lastChar);
                            pushBackCount++;
                        }
                    }
                    else {
                        lastChar = -1;
                        lastCharCount = 0;
                    }
                }
            }
        }
        stack<char> revst;
        while (!st.empty()) {
            revst.push(st.top());
            st.pop();
        }
        int len = revst.size();
        char* result = new char[len + 1];
        int i = 0;
        while (!revst.empty()) {
            result[i++] = revst.top();
            revst.pop();
        }
        result[i] = 0;
        return string(result, result + len);
    }
};

// { Driver Code Starts.

int main() {


    int t; cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        Solution obj;
        cout << obj.Reduced_String(k, s) << "\n";

    }

    return 0;
}  // } Driver Code Ends