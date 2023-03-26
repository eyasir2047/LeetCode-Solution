//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         //int n=abs(r-l)+3;
        /// vector<int>b(10000,0);
        int len1=m-l+1;
        int len2=r-m;
        int b[len1+len2+1000000];
         int i=l;
         int k=l;
         int j=m+1;
         while(i<=m && j<=r ){
             if(arr[i]<arr[j]){
                 b[k]=arr[i];
                 i++;
             }
             else{
                 b[k]=arr[j];
                 j++;
             }
             k++;
         }
         
         if(i<=m){
             while(i<=m){
                 b[k]=arr[i];
                 i++;
                 k++;
             }
         }
         else if(j<=r){
             while(j<=r){
                 b[k]=arr[j];
                 j++;
                 k++;
             }
         }
         
         for(int p=l;p<=r;p++){
             arr[p]=b[p];
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        }
    
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends