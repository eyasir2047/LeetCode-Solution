//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        
        int left=0, right=n-1;
        int mid=left+(right-left)/2;
        
        if(arr[left]<=arr[right]){
            return arr[0];
        }
        
        while(left<right){
            if(arr[mid]>=arr[0]){
                left=mid+1;
            }
            else{//arr[mid]<=arr[n-1]
               right=mid; 
            }
            
            mid=left+(right-left)/2;
        }
        
        return arr[right];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends