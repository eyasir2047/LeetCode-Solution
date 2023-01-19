//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Sorting
{
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];
            
            for(long i = 0; i < n; i++)
             arr[(int)i] = sc.nextLong();
             
            System.out.println(new Solution().inversionCount(arr, n));
            
        }
    }
}

// } Driver Code Ends


//User function Template for Java



class Solution
{
    // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
    
    public static long merge(long[] arr,long l,long r){
        long inv=0;
        
        int mid=(int)(l+(r-l)/2);
        int len1=mid-(int)l+1;
        int len2=(int)r-(int)mid;//r-(mid+1)+1
        
        
        
       
        long[] arr1 = new long[len1];
        long[] arr2 = new long[len2];
        
        int k=(int)l;// mainArrayIndex
        
        for(int i=0;i<len1;i++){
            arr1[i]=arr[k];
            k++;
        }
        for(int i=0;i<len2;i++){
            arr2[i]=arr[k];
            k++;
        }
        
        //merge two sorted array
        
        k=(int)l;
        int index1=0, index2=0;
        
        while(index1<len1 && index2<len2){
            if(arr1[index1]<=arr2[index2]){
                arr[k]=arr1[index1];
                k++;
                index1++;
            }
            else{
                arr[k]=arr2[index2];
                k++;
                index2++;
                inv+=len1-index1;
            }
        }
        
        while(index1<len1){
            arr[k]=arr1[index1];
                k++;
                index1++;
        }
        
        while(index2<len2){
            arr[k]=arr2[index2];
                k++;
                index2++;
        }
        
        return inv;
        
        
    }
    
    public static long mergeSort(long[] arr,long l, long r){
        //base case
        long inv=0;
        if(l<r){
            
    
        long mid=l+(r-l)/2;
       
        
        inv+=mergeSort(arr,l,mid);
        inv+=mergeSort(arr,mid+1,r);
        inv+=merge(arr,l,r);
        
        }
        return inv;
    }
    static long inversionCount(long arr[], long N)
    {
        return mergeSort(arr,0,N-1);
        
    }
    
    
}