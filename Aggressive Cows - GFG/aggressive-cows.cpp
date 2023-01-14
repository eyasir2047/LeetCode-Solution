//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class Solution {
public:
bool ispossible(vector<int> &arr,int n,int k,int mid){
    int cowcount=1, lastposition=arr[0];
    
    for(int i=0;i<n;i++){
         if(cowcount==k) return true;
        if((arr[i]-lastposition)>=mid){
            cowcount++;
            if(cowcount==k) return true;
            lastposition=arr[i];
        }
        
    }
    
    return false;
}

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        sort(stalls.begin(),stalls.end());
        
        int left=0;
        
        int right;
        
       // int maxi=-1;
        
       // for(int i=0;i<n;i++){
        //    maxi=max(maxi,stalls[i]);
       // }
        
        right=stalls[n-1];
        
        int mid=left+(right-left)/2;
        
        int ans=-1;
        
        while(left<=right){
            
            if(ispossible(stalls,n,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
            
            mid=left+(right-left)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends