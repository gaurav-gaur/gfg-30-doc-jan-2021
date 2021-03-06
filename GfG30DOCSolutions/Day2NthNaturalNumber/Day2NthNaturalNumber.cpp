// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends


//User function Template for C++


class Solution {
public:
	long long findNth(long long N)
	{
		// code here.
		// Convert to base 9 because base 9 number will have
		// only 0 to 8 digits in it, hence all numbers having 9 will 
		// be eliminated
		long long n = N, r;
		int i = 0;
		long long result = 0; // count all such numbers
		while (n > 0) {
			r = n % 9;
			n = n / 9;
			result = result + (long long)(pow(10, i)) * r;
			i++;
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
		long long n, ans;
		cin >> n;
		Solution obj;
		ans = obj.findNth(n);
		cout << ans << endl;
	}
}

// } Driver Code Ends