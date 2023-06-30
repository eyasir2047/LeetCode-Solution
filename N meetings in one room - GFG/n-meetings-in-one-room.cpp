//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        static bool  cmp(pair<int,int> v1, pair<int,int>v2)//{1,3}
{
   return v1.second<v2.second;
}
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
         //{start,end}//{{2,3},{3,5},...}
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        
        int endtime=v[0].second;
        int cnt=1;
        
        for(int i=1;i<n;i++){
            int startTime=v[i].first;
            if(startTime>endtime){
                cnt++;
                endtime=v[i].second;
            }
        }
     return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends