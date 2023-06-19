//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   public:
    void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
        vis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child]){
                dfs(child,vis,st,adj);
            }
        }
        st.push(node);
    }
    
    void dfs3(int node,vector<int>&vis,vector<int>adjR[]){
         vis[node]=1;
        for(auto child: adjR[node]){
            if(!vis[child]){
                dfs3(child,vis,adjR);
            }
        }
        
    }
    
   
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //kosaraju algorithm-> 1) sort according to time and store it into the stack
        //2) reverse the edge
        //3) again dfs and count the scc
        
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        vector<int>adjR[V];
        //i->child, now child->i
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto child:adj[i]){
                adjR[child].push_back(i);
            }
        }
         
        
        int scc=0;
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node,vis,adjR);
            }
        }
        
        return scc;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends