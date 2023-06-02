//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 

int getpivot(vector<int> arr, int n){
    
   
    int left=0, right=n-1;
    
    //if the array is sorted but not rotated
    if(arr[left]<=arr[right]) return -1;
    
    int mid=left+(right-left)/2;
    
    while(right>left){
        if(arr[mid]>=arr[0]){
            left=mid+1;
        }
        else{//arr[n-1]>=arr[mid]
        
        right=mid;
            
        }
        
        mid=left+(right-left)/2;
        
    }
    
    return right;
}

int binarysearch(vector<int> arr,int left, int right,int x ){
     int mid=left+(right-left)/2;
     while(left<=right){
         if(arr[mid]==x) return mid;
         
         else if(arr[mid]>x) {
            right=mid-1;
         }
         else{
             left=mid+1;
         }
         mid=left+(right-left)/2;
     }
     
     return -1;
}
int Search(vector<int> vec, int K) {
    //code here
    int n=vec.size();
    
    int pivot=getpivot(vec,n);
    
    if(K<=vec[n-1] && K>=vec[pivot]){
        return binarysearch(vec,pivot,n-1,K);
    }
    else{
        return binarysearch(vec,0,pivot-1,K);
    }
    
    
}
