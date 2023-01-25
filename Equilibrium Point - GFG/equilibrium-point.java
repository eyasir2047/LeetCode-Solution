//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.util.stream.*;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t =
            Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {
            
            //taking input n
            int n = Integer.parseInt(br.readLine().trim());
            long arr[] = new long[n];
            String inputLine[] = br.readLine().trim().split(" ");
            
            //adding elements to the array
            for (int i = 0; i < n; i++) {
                arr[i] = Long.parseLong(inputLine[i]);
            }

            Solution ob = new Solution();
            
            //calling equilibriumPoint() function
            System.out.println(ob.equilibriumPoint(arr, n));
        }
    }
}
// } Driver Code Ends


class Solution {

    
    // a: input array
    // n: size of array
    // Function to find equilibrium point in the array.
    public static int equilibriumPoint(long arr[], int n) {

        // Your code here
        int total_sum=0;
        
        for(int i=0;i<n;i++){
            total_sum+=arr[i];
            
        }
        int left_sum=0; //1 3 5 2 2
                        //total_sum=13
        
        for(int i=0;i<n;i++){
           
            total_sum-=arr[i];//right sum, 12 ,9,4
            if(left_sum==total_sum){
                return i+1;
            }
             left_sum+=arr[i]; //1,4 
        }
        
        return -1;
    }
}
