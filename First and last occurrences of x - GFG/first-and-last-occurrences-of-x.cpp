//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int first_ele(int arr[],int n,int x){
    int low=0, high=n-1;
    int mid=low+(high-low)/2;
    int ans=-1;
    while(low<=high){
    
   // if((mid==0 || (mid!=0 && arr[mid-1]<arr[mid]) ) && arr[mid]==x ){
   //     return mid;
   // } 
   if(arr[mid]==x){
       ans=mid;
       high=mid-1;
   }
    else if(arr[mid]>x) high=mid-1;
    else low=mid+1;
    
    mid=low+(high-low)/2;
    
    }
    
    return ans;
}
int second_ele(int arr[],int n,int x){
    int low=0, high=n-1;
    int mid=low+(high-low)/2;
    while(low<=high){
    
    if((mid==n-1 || (mid!=n-1 && arr[mid+1]>arr[mid]) ) && arr[mid]==x ){
        return mid;
    } 
   //if(arr[high]==mid){
       
   //}
    else if(arr[mid]>x) high=mid-1;
    else low=mid+1;
    
    mid=low+(high-low)/2;
    
    }
    
    return -1;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    int first=first_ele(arr,n,x);
    int second=second_ele(arr,n,x);
    
    vector<int>ans;
    
    ans.push_back(first);
    ans.push_back(second);
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends