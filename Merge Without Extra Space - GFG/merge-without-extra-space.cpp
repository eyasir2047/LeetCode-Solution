//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
       { 
        
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
                i--;
                j++;
            
        }
        
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        // 1 3 5 7.        0 2 6 8 9 
        //1 3 2 0         7 5 6 8 9
        //0 1 2 3.        5 6 7 8 9
        
         
            // code here 
            /*
            //gap algorithm /method
            int gap=ceil(1.0* (n+m)/2);
            while(gap!=1){
                
                for(int i=0,j=gap;i<(n+m) && j<(n+m);i++,j++){
                    if(i<n && j<n){
                        if(arr1[i]>arr1[j]){
                            swap(arr1[i],arr1[j]);
                        }
                    }
                    else if(i<n && j>=n){
                       if(arr1[i]>arr2[j]){
                            swap(arr1[i],arr2[j]);
                        } 
                    }
                    else if(i>=n && j>=n){
                        if(arr2[i]>arr2[j]){
                            swap(arr2[i],arr2[j]);
                        } 
                    }
                }
                gap=ceil(gap/2.0);
            }
            */
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends