//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here //two pointer approach
        long long int  max_left=0, max_right=0;
         long long int ans=0;
        long long  int left=0, right=n-1;
        
        while(left<=right){
            if(arr[left]<=arr[right]){//ensuring that there is a building in right, whose hight is bigger
                if(max_left<=arr[left]){
                    max_left=arr[left];
                }
                else{
                    ans+=max_left-arr[left];//ans+=min(max_left,max_right)-arr[left]
                }
                left++;
            }
            else{//ensuring that there is a building in left, whose hight is bigger
                if(max_right<=arr[right]){
                    max_right=arr[right];
                }
                else{
                    ans+=max_right-arr[right];
                }
                right--;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends