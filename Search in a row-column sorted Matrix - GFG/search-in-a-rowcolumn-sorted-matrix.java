//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG{
	public static void main(String args[]) throws IOException { 
		Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t > 0){
       		int rows=sc.nextInt();
       		int columns=sc.nextInt();
			
			int matrix[][]=new int[rows][columns];
          
        	for(int i=0; i<rows;i++){            
            	for(int j=0; j<columns;j++){
                	matrix[i][j]=sc.nextInt();
            	}
         	}
         	int target = sc.nextInt();
         	
			Solution x = new Solution();
			
			if (x.search(matrix, rows, columns, target)) 
				System.out.println(1); 
			else
				System.out.println(0); 
			t--;
		}
	} 
}
// } Driver Code Ends




class Solution 
{ 
    //Function to search a given number in row-column sorted matrix.
	static boolean search(int matrix[][], int n, int m, int x) 
	{  
	    // code here 
	    
	    int i=0,j=m-1;
	    while(i<n && j>=0){
	       if(matrix[i][j]==x){
	           return true;
	       }
	       else if(x>matrix[i][j]){
	           i++; // x ar boro hole onno column ai jete hobe
	       }
	       else{
	           j--; //x ar value kom hole oi row te element search korte hobe
	       }
	    }
	    
	 
	    /*
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==x){
	                return true;
	            }
	        }
	    }*/
	    
	    return false;
	} 
} 
