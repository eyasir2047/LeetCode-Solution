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
int Search(vector<int> arr, int K) {
    //code here
    
    int n=arr.size();
    
    int left=0,right=n-1;
    
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==K)return mid;
        else if(arr[mid]>=arr[left]){
            if(K>=arr[left] && K<=arr[mid]){
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        else{ // arr[mid]<arr[left]
            if(K>=arr[mid] && K<=arr[right]){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    
    return -1;
    
    
}