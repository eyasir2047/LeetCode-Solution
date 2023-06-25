//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool checkAP(int v, int parent, int time, vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<vector<int>> &adj){
        visited[v] = true;
        int child=0;
        low[v] = disc[v] = ++time;
        for(auto it:adj[v]){
            if(!visited[it]){
                ++child;
                if(checkAP(it,v,time,visited,disc,low,adj)){
                    return true;
                }
                low[v] = min(low[v],low[it]);
                if(parent != -1 && low[it] >= disc[v]){
                    return true;
                }
                
            }else if(it != parent){
                low[v] = min(low[v],disc[it]);
            }
        }
        if(parent == -1 && child > 1){
            return true;
        }
        return false;
    }
    int biGraph(int arr[], int n, int e) {
        // code here
        // a graph is biconnected means no articulation point 
        vector<vector<int>> adj(n);
        for(int i=0;i<2*e;i=i+2){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
        }
        vector<bool> visited(n,false);
        vector<int> disc(n,0),low(n);
        int parent=-1,time=0;
        if(checkAP(0,parent,time,visited,disc,low,adj)){
            return false;
        }
        for(int i=0;i<n;++i){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}
// } Driver Code Ends