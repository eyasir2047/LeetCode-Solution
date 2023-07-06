//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool func(vector<int>&arr,int n,int sum,vector<vector<int>>&dp){
    if(sum==0)return true;
    //sum==0 && n==0-> return true;
    if(n==0)return false;
    
    if(dp[n][sum]!=-1){
        
        return dp[n][sum]==1?true:false;
    }
    
    if(arr[n-1]<=sum)
    return dp[n][sum]=func(arr,n-1,sum-arr[n-1],dp)|| func(arr,n-1,sum,dp);
    else
    return dp[n][sum]=func(arr,n-1,sum,dp);
}

    bool isSubsetSum(vector<int>arr, int sum){
     
      int n=arr.size();
      
      vector<vector<int>>dp(n+10,vector<int>(sum+10,-1));
      bool ans=func(arr,n,sum,dp);
      return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends