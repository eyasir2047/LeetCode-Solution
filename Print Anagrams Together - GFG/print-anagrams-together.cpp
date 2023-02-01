//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        //vector<vetor<string>> ....(2D array)
        int n=string_list.size();
        
        map<string,vector<string>>mp;
        
        for(int i=0;i<n;i++){
            string s=string_list[i];
            sort(s.begin(),s.end());
            mp[s].push_back(string_list[i]);
        }
        
        vector<vector<string>>ans(mp.size());
        
        int indx=0;
        
        for(auto i:mp){
            auto v= i.second;//this is a vector
            
            for(int k=0;k<v.size();k++){
                ans[indx].push_back(v[k]); //row
               
            }
            
             indx++;
        }
        
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends