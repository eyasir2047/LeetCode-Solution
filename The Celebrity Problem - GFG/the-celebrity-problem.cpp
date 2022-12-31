//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    int knows(vector<vector<int>>&M,int a,int b){
        if(M[a][b]==1) return true;
        else return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        //step1: push all the elements to the stack
        for(int i=0;i<n;i++){
            s.push(i); //ai line ta buji nai
        }
        
        //step-2: get two elements and pop until s.size()>1
        while(s.size()>1){
            int a,b;
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            if(knows(M,a,b)) {
                s.push(b);//a can't be celebrity
            }
            else{
                s.push(a);
            }
            
        }
       // step3: single element can't be a potential candidate
       int candidate=s.top();
       //varify , rowcheck & colcheck
       int zerocount=0;
       for(int i=0;i<n;i++){
           if(M[candidate][i]==0) zerocount++;
       }
       if(zerocount!=n)  return -1;
       int onecount=0;
       for(int i=0;i<n;i++){
           if(M[i][candidate]==1) onecount++;
       }
       if(onecount!=n-1) return -1;
       
       return candidate;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends