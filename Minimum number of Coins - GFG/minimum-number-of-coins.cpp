//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
       
        int cnt=0;
        vector<int>arr={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        reverse(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(arr[i]<=N){
                cnt++;
                ans.push_back(arr[i]);
                N-=arr[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends