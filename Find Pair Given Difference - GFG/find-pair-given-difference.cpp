//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    
  //  int left=arr[0], right=arr[size-1];
    //int mid=left+(right-left)/2;
    
    //int ans=-1;
    
    int i=0, j=1;
    
    while(i<size && j<size){
        if(abs(arr[j]-arr[i])==n){
            return  true;
        }
        
        if(abs(arr[j]-arr[i])<n){
            j++;
        }
        else{
            i++;
            if(i==j) j++;
        }
    }
    
    return false;
    
    
    
}