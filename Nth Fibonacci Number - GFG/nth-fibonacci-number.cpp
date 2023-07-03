//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
//   long long int fib(long long int t[],long long int n){
//       if(n==0 || n==1)return n;
      
//       if(t[n]!=-1)return t[n];
      
//       return t[n]= fib(t,n-1)+fib(t,n-2);
//   } 

long long int fib(long long int n,long long int t[]){
    if(n<=1)return n%1000000007;
    
    if(t[n]!=-1)return t[n]%1000000007;
    
    return t[n]=(fib(n-1,t)%1000000007+fib(n-2,t)%1000000007)%1000000007;
}
    long long int nthFibonacci(long long int n){
        // // code here
        // long long int t[100000];
        // memset(t,-1,sizeof(t));
        
        // return fib(t,n);
        
        long long int t[1002];
        memset(t,-1,sizeof(t));
        
      return fib(n,t);
       
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends