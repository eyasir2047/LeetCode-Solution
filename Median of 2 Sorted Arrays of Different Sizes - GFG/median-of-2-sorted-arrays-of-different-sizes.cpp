//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        
        int m=array1.size();
        int n=array2.size();
        if(m>n) return MedianOfArrays(array2,array1);
        
        int left=0, right=m;
        int partitionX, partitionY;
        
        while(left<=right){
            partitionX=left+(right-left)/2;
            partitionY=(m+n+1)/2-partitionX; // (m+n+1)/2, as I need the ceil value
            
            int maxLeftX= (partitionX==0) ? INT_MIN: array1[partitionX-1];
            int minRightX= (partitionX==m) ? INT_MAX: array1[partitionX];
            
            int maxLeftY= (partitionY==0) ? INT_MIN: array2[partitionY-1];
            int minRightY= (partitionY==n) ? INT_MAX: array2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((m+n)%2==0){
        return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                }
                else{
                    return (double)(max(maxLeftX,maxLeftY));
                }
            }
            else if(maxLeftX>minRightY){
                right=partitionX-1;
            }
            else{
                left=partitionX+1;
            }
        }
        
        return 0.0;
        
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends