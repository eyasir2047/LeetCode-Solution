//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //{u,{v,w}} and {v,{u,w}}//adjacency list
        //and for priority_queue-> {{x1,y1},{x2,y2},{x3,y3}}
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int>dt(n+1,1e9);
        vector<int>parent(n+1);
       // vector<bool>visited(n+1,false);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int source=1;
        dt[source]=0;
        pq.push({0,source});
      //  visited[source]=true;
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
          //  if(!visited[node]){
               // visited[node]=true;
            for(auto child:adj[node]){
                int adjNode=child.first;
                int edgeW=child.second;
                if(edgeW+dist<dt[adjNode]){
                    dt[adjNode]=dist+edgeW;
                    pq.push({dt[adjNode],adjNode});
                    parent[adjNode]=node;
                }
           // }
            }
        }
        
        if(dt[n]==1e9)return {-1};
        
        vector<int>ans;
        int i=n;
        while(parent[i]!=i){
            ans.push_back(i);
            i=parent[i];
        }
        ans.push_back(source);
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends