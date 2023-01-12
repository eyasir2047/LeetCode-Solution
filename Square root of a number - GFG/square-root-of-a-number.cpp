//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{

#define ll long long int 

  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        if(x<2) return 1;
        
        ll left=2, right=x/2;
        
        ll mid=0;
        
        ll num=0;
        
        while(left<=right){
            
            mid=left+(right-left)/2;
            
            num=mid*mid;
            
            if(num>x)  right=mid-1;
            
            else if(num<x) left=mid+1;
            
            else return mid;
            
        }
        
        return right;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends