//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(pair<int,double>v1,pair<int,double>v2){
        return v1.second>v2.second;//descending order
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        //{index,ratio}
        //{{a1,b1},{a2,b2}}
        vector<pair<int,double>>v;
        for(int i=0;i<n;i++){
            double x=arr[i].value/(double)arr[i].weight;
            v.push_back({i,x});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int capacity=W;
        double ans=0;
        
        for(int i=0;i<n;i++){
            int indx=v[i].first;
            int p=arr[indx].weight;
            if(capacity>=p){
                int k=arr[indx].value;
                ans+=k;
                capacity-=p;
            }else{
                ans+=(v[i].second*capacity);
                capacity=0;
                break;
            }
        }
        
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends