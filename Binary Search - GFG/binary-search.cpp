//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    
    int binary(int arr[],int left,int right,int ele){
        if(left>right)return -1;
        else{
            int mid=left+(right-left)/2;
            if(arr[mid]==ele) return mid;
            else if(arr[mid]<ele){
                binary(arr,mid+1,right,ele);
            }
            else binary(arr,left,mid-1,ele);
        }
    }
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int left=0, right=n-1;
        int ans=0;
         ans= binary(arr,left,right,k);
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends