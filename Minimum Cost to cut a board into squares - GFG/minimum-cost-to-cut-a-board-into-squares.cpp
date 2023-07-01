//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        sort(X.rbegin(),X.rend());
        sort(Y.rbegin(),Y.rend());
        
        int m=M;
        int n=N;
        
        int i=0,j=0;
        int vp=1,hp=1;
        int cost=0;
        
        while(i<m-1 && j<n-1){
            if(X[i]<=Y[j]){
                cost+=Y[j]*vp;
                hp++;
                j++;
            }else{
                cost+=X[i]*hp;
                vp++;
                i++;
            }
        }
        
        while(i<m-1){
             cost+=X[i]*hp;
                vp++;
                i++;
        }
        while(j<n-1){
                cost+=Y[j]*vp;
                hp++;
                j++;
        }
        return cost;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends