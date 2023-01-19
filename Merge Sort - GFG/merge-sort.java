//{ Driver Code Starts
import java.util.*;

class Merge_Sort
{
    //method to print the elements of the array
	static void printArray(int arr[])
    {
        StringBuffer sb=new StringBuffer("");
        int n = arr.length;
        for (int i=0; i<n; ++i)
            sb.append(arr[i]+" ");
        System.out.println(sb.toString());
    }

    

	public static void main(String args[])
	{
	    //taking input using Scanner class
		Scanner sc = new Scanner(System.in);
		
		//taking testcases
		int T = sc.nextInt();
		while(T>0)
		{
		    //taking elements count
			int n = sc.nextInt();
			
			//creating an object of class Merge_Sort
			Merge_Sort ms = new Merge_Sort();
			
			//creating an array of size n
			int arr[] = new int[n];
			
			//adding elements to the array
			for(int i=0;i<n;i++)
				arr[i] = sc.nextInt();

            
			Solution g = new Solution();
			
			//calling the method mergeSort
			g.mergeSort(arr,0,arr.length-1);

            //calling the method printArray
			ms.printArray(arr);
		T--;
		}
	}
}



// } Driver Code Ends


class Solution
{
    void merge(int arr[], int l, int m, int r)
    {
         int len1=m-l+1;
         int len2= r-(m+1)+1;//r-m
         
        int[] arr1 = new int[len1];
        int[] arr2 = new int[len2];
         
         int k=l; // k=orginalMainIndex
         
         for(int i=0;i<len1;i++){
             arr1[i]=arr[k];
             k++;
            
         }
         
         for(int i=0;i<len2;i++){
             arr2[i]=arr[k];
             k++;
        }
        
        k=l;
        
        //merge two sorted array
        
        int index1=0, index2=0;
        
        while(index1<len1 && index2<len2){
            if(arr1[index1]<arr2[index2]){
                arr[k]=arr1[index1];
                k++;
                index1++;
            }
            else{
                arr[k]=arr2[index2];
                k++;
                index2++;
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
        
        
         
         
    }
    void mergeSort(int arr[], int l, int r)
    {
        
            if(l>=r){  // base case
                return ;
            }
       
        
        int mid=l+(r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
        
        
    }
}
