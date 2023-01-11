//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        if(N<2) return 0;//N=8
        
        int left=1;
        int right=N;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
           // int num=mid*mid;
            if(mid<=N/mid) 
            {
                if( N % mid==0 && mid==(N/mid) )
                {
                    return mid-1;
                }
                left=mid+1;
            }
            else right=mid-1;
        }
        return right;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends