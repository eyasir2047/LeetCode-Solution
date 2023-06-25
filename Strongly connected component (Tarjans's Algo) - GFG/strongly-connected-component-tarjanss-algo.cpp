//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
	
	void dfs(int curr,vector<int>adj[],vector<int>&dt,vector<int>&low,stack<int>&st,
	vector<bool>&instack,vector<vector<int>>&ans){
	    static int time=0;
	    dt[curr]=low[curr]=time;
	    time++;
	    st.push(curr);
	    instack[curr]=true;
	    
	    for(auto child:adj[curr]){
	        if(dt[child]==-1){
	            dfs(child,adj,dt,low,st,instack,ans);
	            low[curr]=min(low[curr],low[child]);
	        }
	       else if(instack[child]){//back edge condition
	           low[curr]=min(low[curr],dt[child]);
	       }
	    }
	  
	    
	    if(low[curr]==dt[curr]){// curr is the head of SCC
	        vector<int>res;
	        while(st.top()!=curr ){
	            res.push_back(st.top());
	            instack[st.top()]=false;
	            st.pop();
	        }
	        
	            res.push_back(st.top());
	            instack[st.top()]=false;
	            st.pop();
	        sort(res.begin(),res.end());
	        ans.push_back(res);
	    }
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        //tarjan's algorithm-> bridge, articulation point, strongly connected components and 
        // topological sort 
        vector<int>dt(V,-1);
        vector<int>low(V,-1);
        vector<bool>instack(V,false);
        stack<int>st;
       
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(dt[i]==-1){
                dfs(i,adj,dt,low,st,instack,ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
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

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends