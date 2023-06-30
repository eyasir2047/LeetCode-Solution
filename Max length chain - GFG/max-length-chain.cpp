//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
static bool cmp(pair<int,int>v1,pair<int,int>v2){
    return v1.second<v2.second;
}
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({p[i].first,p[i].second});
        }
        sort(v.begin(),v.end(),cmp);
        
        int endchain=v[0].second;
        int cnt=1;
        
        for(int i=1;i<n;i++){
            int startchain=v[i].first;
            if(startchain>endchain){
                cnt++;
                endchain=v[i].second;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends