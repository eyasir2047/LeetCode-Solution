//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
         vector<long long>left;
       stack<pair<long long, long long>>s;
       int pseudoindex = -1;
    //   long long i;
     
       for(int i=0; i<n; i++)
       {
           if(s.size()==0)             //if stack is empty
               left.push_back(pseudoindex);
           else if( s.size()>0 && s.top().first<arr[i])
               left.push_back(s.top().second);
           else if(s.size()>0 && s.top().first>=arr[i])
           {
               while(s.size()>0 && s.top().first>=arr[i])
                   s.pop();
               
               if(s.size()==0)
                   left.push_back(pseudoindex);
               else
                   left.push_back(s.top().second);
           }
           s.push({arr[i],i});
       }
       
    //   while(!s.empty())
    //       s.pop();
           
       //NSR
       
       vector<long long>right;
       stack<pair<long long, long long>>s1;
        pseudoindex = n;
       
       for( int i=n-1; i>=0; i--)
       {
           if(s1.size()==0)             //if stack is empty
               right.push_back(pseudoindex);
           else if( s1.size()>0 && s1.top().first<arr[i])
               right.push_back(s1.top().second);
           else if(s1.size()>0 && s1.top().first>=arr[i])
           {
               while(s1.size()>0 && s1.top().first>=arr[i])
                   s1.pop();
               
               if(s1.size()==0)
                   right.push_back(pseudoindex);
               else
                   right.push_back(s1.top().second);
           }
           s1.push({arr[i],i});
       }
       reverse(right.begin(),right.end());
       
       
       //obtaining area by calculating width
       
       // dont use extra vectors to calculate width, memory overflows  
       
        for(int i=0;i<n;i++)
          right[i] = right[i]-left[i]-1;
          
          for( int i=0;i<n;i++){
              right[i] = arr[i]*right[i];
          }
        long long max=right[0];
        for(int i=0;i<n;i++)
            
                if(right[i]>max)
                max = right[i];
            
        return max;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends