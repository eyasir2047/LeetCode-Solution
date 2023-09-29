//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define ll long long int 
const ll N=1e5+10;
ll dp[N];
class Solution{
  public:
  
  int func(ll len,vector<ll>&prices){
    if(len==0)return 0;
    if(dp[len]!=-1)return dp[len];

    ll ans=0;

    for(ll rod_to_cut=1;rod_to_cut<=prices.size();rod_to_cut++){
        if(len-rod_to_cut>=0)
        ans=max(ans,func(len-rod_to_cut,prices)+prices[rod_to_cut-1]);
    }

    return dp[len]=ans;
}




//0(N^2)
    int cutRod(int price[], int n) {
        //code here
        memset(dp,-1,sizeof(dp));
        vector<ll>prices(price,price+n);
        return func(n,prices);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends