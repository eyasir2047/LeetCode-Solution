//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long int
class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        ll cnt=0;
        map<ll,ll>mp;
        
        for(ll i=0;i<n;i++){
            mp[arr[i]%k]++;
        }
        
        for(auto i: mp){
            cnt+=(i.second*(i.second-1))/2;
        }
       
        
        return cnt;
        
            
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends