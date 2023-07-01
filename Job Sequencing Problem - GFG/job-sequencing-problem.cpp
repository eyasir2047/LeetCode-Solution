//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static comp (Job a,Job b)
    {
        return a.profit>b.profit;
    }
   
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //{deadline,profit}={{x1,y1},{x2,y2},....}
        sort(arr,arr+n,comp);
        int lastDead=0;
        for(int i=0;i<n;i++)
        {
            lastDead = max(lastDead,arr[i].dead);
        }
        
        vector<int> deadlines(lastDead+1,-1);
        int maxprofit=0;
        int jobs=0;
        for(int i=0;i<n;i++)
        {
            int dead= arr[i].dead;
            for(int j=dead;j>= 1;j--)
            {
                if(deadlines[j]==-1)
                {
                    deadlines[j]=arr[i].id;
                    jobs++;
                    maxprofit+=arr[i].profit;
                    break;
                }
            }
        }
        return {jobs,maxprofit};
      
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends