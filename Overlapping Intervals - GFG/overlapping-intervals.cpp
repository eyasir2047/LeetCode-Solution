//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         
         // Initialize an empty array to store the merged intervals
         vector<vector<int>>mergeinterval;
         
         // If the input array is empty, return an empty array
         if(intervals.size()==0) return mergeinterval;
         
         // Sort the input array based on the start time of each interval
         sort(intervals.begin(),intervals.end());
         
         // Initialize a temporary interval with the first interval in the sorted array
         vector<int>temp=intervals[0]; 
         
         // Iterate through the sorted intervals
         for(auto it: intervals){
            // Check if the next interval's start time is less than or equal to the current interval's end time
            if(it[0]<=temp[1]){ 
                // If it is, update the current interval's end time to be the maximum of the current end time and the next interval's end time
                temp[1]=max(it[1],temp[1]);
            }
            else{
                // If not, add the current interval to the merged intervals array
                mergeinterval.push_back(temp);
                // Make the next interval the current interval
                temp=it;
            }
        }
         // Add the last current interval to the merged intervals array
         mergeinterval.push_back(temp);
         // Return the merged intervals array
         return mergeinterval;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends