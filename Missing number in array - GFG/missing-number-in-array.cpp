//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        
        
        int ans=0;
        
        for(int i=0;i<n-1;i++){
            ans=ans^array[i];
        }
        for(int i=1;i<=n;i++){
            ans=ans^i;
        }
        return ans;
        
        //this method is not current because of integer overflow
        /*
        sort(array.begin(),array.end());
        int i=0;
        for( i=0;i<n;i++){
            if(array[i]!=i+1){
                break;
            }
        }
        return i+1;
        */
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends