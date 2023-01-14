//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool ispossible(int A[], int N, int M, int mid){
        
        int pagesum=0, studentcount=1;
        if(N<M) return false;
        
        for(int i=0;i<N;i++){
            if((pagesum+A[i])<=mid){
                pagesum+=A[i];
            }
            else{
                studentcount++;
                
                if(studentcount>M || A[i]>mid) return false;
                
               // pagesum=0;
                pagesum=A[i];//pagesum=A[i];
            }
            
            if(studentcount > M)  return false;
        
        }
        return true;
    }
    
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        int left=0;
        int right;
        
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        
        right= sum;
        
        int mid=left+(right-left)/2;
        
        int ans=-1;
        
        while(left<=right){
            
            if(ispossible(A,N,M,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
            
            mid=left+(right-left)/2;
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends