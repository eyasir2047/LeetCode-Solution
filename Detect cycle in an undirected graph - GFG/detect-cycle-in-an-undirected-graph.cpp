//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(vector<int>adj[],bool vis[],int src){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto child: adj[node]){
                if(!vis[child]){
                    vis[child]=1;
                    q.push({child,node});
                }else if(parent!=child){
                    return true;
                }
            }
        }
        
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(detect(adj,vis,i))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends