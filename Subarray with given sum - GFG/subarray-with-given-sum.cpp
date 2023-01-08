//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
#define ll long long int 
//define rep(i,a,b) for(ll i=a;i<=b;i++)
//hashmap or hashset

{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        //two pointer appraoch
        int i=0,j=0;
        int sum=0;
        int flag=0;
        vector<int>k(1,0);
        if(s==0 || s<0){
            k[0]=-1;
            return k;
        } 
       
        for(i=0;i<n;i++){
            sum+=arr[i];
            while(sum>s){
                sum-=arr[j];
                j++;
            }
            if(sum==s){
                flag=1;
                break;
            }
        }
        
        
        
       
        
        vector<int>v(2,0);
        v[0]=j+1;
        v[1]=i+1;
        vector<int>a(1,0);
        if(flag==0){
            a[0]=-1;
            return a;
        }
        
       // System.out.println(i+" "+j);
       return v;
        
      
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends