//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void dfs(int vertex,vector<int>adj[],bool visited[],vector<int>&ans){
      visited[vertex]=true;
      
      ans.push_back(vertex);
      
      for(auto child: adj[vertex]){
          if(visited[child])continue;
          
          dfs(child,adj,visited,ans);
      }
  }
        
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        
        bool visited[V]={0};
        
        dfs(0,adj,visited,ans);
        
        
       
       return ans;
        
        
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends