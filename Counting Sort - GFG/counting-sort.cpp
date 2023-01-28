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
        int n=arr.size();
        int count[26]={0};
        for(int i=0;i<n;i++){
            count[arr[i]-'a']++;
        }
        
        //prefix sum
        
        for(int i=1;i<26;i++){
            count[i]=count[i]+count[i-1];
        }
        
        char result[n];
        
        //stable sort
        
        for(int i=n-1;i>=0;i--){
            result[--count[arr[i]-'a']]=arr[i];
        }
        
        string s;
        for(int i=0;i<n;i++){
            s+=result[i];
        }
        return s;
        
        
/*
   // int maxi=INT_MIN;

   // for(int i=0;i<n;i++){
    //    maxi=max(maxi,arr[i]);

 //   }
 int n=arr.size();

    vector<int>count(26,0);

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }


    //prefix sum

    for(int i=1;i<=26;i++){
        count[i]=count[i]+count[i-1];
    }

   // vector<string>output(n,0);
   
   char output[n];

    for(int i=0;i<n;i++){

        output[count[arr[i]-1]]=arr[i];
        --count[arr[i]];

    }

    //for(int i=0;i<n;i++){
      //  arr[i]=output[i];
   // }
   
   return output;
    
   */     
        
       
        
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