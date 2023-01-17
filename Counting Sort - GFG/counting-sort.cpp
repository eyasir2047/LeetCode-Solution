//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        int count[26]={0};
        int n=arr.size();
        for(int i=0;i<n;i++){
            count[arr[i]-'a']++;
        }
        //abcde. // 1 1 1 1 1
        //aaabbddd 3 2 0 3 
        int index=0;
        for(int i=0;i<=25;i++){
            while(count[i]>0){
                arr[index]= 'a'+i;
                index++;
                count[i]--;
            }
        }
        
        return arr;
        
        
       
        
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
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends