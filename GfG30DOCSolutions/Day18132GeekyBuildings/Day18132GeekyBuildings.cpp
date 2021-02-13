// { Driver Code Starts
//Initial template for C++

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// } Driver Code Ends


//User function template for C++

class Solution {
public:
	bool recreationalSpot(int arr[], int n) {
		// Ranges denote all the ranges which have non overlapping
		// min and max
		// We can stop our search when we find third building 
		// between any of these non overlapping ranges
		// Overlapping ranges can actually be merged
		vector<pair<int, int> > ranges;
		int min = arr[0];
		bool partialRange = true;
		int i;
		for (i = 1; i < n; i++) {
			if (!ranges.empty()) {
				// Always check third building in all valid ranges
				for (auto it = ranges.begin(); it != ranges.end(); it++) {
					if (arr[i] > it->first && arr[i] < it->second) {
						return true;
					}
				}
				// If the next element is smaller than the first element
				// of the last range (which will be smallest always)
				// Example: 
				// I/P: 6 9 3 2 1 5 13 2
				// Range1 : 6 - 9
				// So when 3 is added it's the lower than 6
				if (arr[i] < ranges.at(ranges.size() - 1).first) {
					if (partialRange) {
						// This scenario is partial range has started
						// but we are continuously finding lower elements
						// for example 2 and 1 followed by 3 in the 
						// selected I/P
						if (arr[i] < min) {
							min = arr[i];
						}
						// So arr[i] is lesser than the existing ranges
						// but greater than min, then
						else {
							ranges.push_back(make_pair(min, arr[i]));
							partialRange = false;
						}
					}
					// start new partial range
					else {
						min = arr[i];
						partialRange = true;
					}
				}
				else {
					if (partialRange != true) {
						// If we find an element which is bigger than any of the
						// ranges max value, then all the below ranges can be 
						// merged in one
						bool mergeCondition = false;
						auto it = ranges.begin();
						for (; it != ranges.end(); it++) {
							if (arr[i] > it->second) {
								// merge ranges from last up to this range
								// pick min from the last range if there is
								// no partial range
								if (partialRange != true)
									min = ranges.at(ranges.size() - 1).first;
								mergeCondition = true;
								break;
							}
						}
						if (mergeCondition) {
							ranges.erase(it, ranges.end());
							ranges.push_back(make_pair(min, arr[i]));
							partialRange = false;
						}
					}
					else {
						ranges.push_back(make_pair(min, arr[i]));
						partialRange = false;
					}
				}
			}
			// Until the first range is added, control will always come here
			else {
				// If we contiuously encounter new min elements then we 
				// should update the min
				if (arr[i] < min) {
					min = arr[i];
				}
				// As soon as we find the first greater element than 
				// the previous min, we start a new range
				else {
					ranges.push_back(make_pair(min, arr[i]));
					partialRange = false;
				}
			}
		}
		return false;
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
		Solution ob;
		if (ob.recreationalSpot(arr, n))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	return 0;
}  // } Driver Code Ends