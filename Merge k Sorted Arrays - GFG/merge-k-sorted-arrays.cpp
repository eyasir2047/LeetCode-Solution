//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
       
        //vector of vector-->2D array
        //k is row numbers
        
       // priority_queue<pii,vector<pii>>pq;-> general structure
       //but for minheap
       priority_queue<pii,vector<pii>,greater<pii>>pq;//minheap
       
       for(int i=0;i<K;i++){
           pq.push({arr[i][0],i});//taking the first element from each sorted array
       }
       
       vector<int>idx(K,0);
       vector<int>ans;
       
       while(!pq.empty()){
           auto x=pq.top();
           ans.push_back(x.first);
           pq.pop();
           
           
           if(idx[x.second]+1<arr[x.second].size()){
               pq.push({arr[x.second][idx[x.second]+1],x.second});
               
           }
           idx[x.second]+=1;
           
       }
       
       return ans;
       
        
        
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends