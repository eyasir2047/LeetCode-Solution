//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int vertex,vector<bool>&color,vector<int>adj[],vector<int>&visited){
        
            visited[vertex]=1;
            
        for(auto child:adj[vertex]){
          
            if(!visited[child]){
            color[child]=!color[vertex];
            if(dfs(child,color,adj,visited)==false)return false;
            }
             else if(color[vertex]==color[child]) return false;
            
        }
        
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool>color(V);
	    color[0]=0; 
	    vector<int>visited(V,0);
	   
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(!dfs(i,color,adj,visited)){
	             return false;
	         }
	        }
	    }
	    
	    return true;
	     
	    
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends