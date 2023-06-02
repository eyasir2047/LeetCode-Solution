//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int K){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
         int n=l+h+1;
    
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
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends