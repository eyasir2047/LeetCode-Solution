//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

#include<iostream>
#include<climits>
#include<stdio.h>

class MaxHeap{

    int *arr;
    int capacity;
    int size;
    
    public:
    MaxHeap(int capacity){
        this->capacity=capacity;
        this->size=0;
        arr=new int[capacity];
    }

    int parent(int v){
        return (v-1)/2;
    }

    int left(int v){
        return 2*v+1;
    }

    int right(int v){
        return 2*v+2;
    }

    void insertKey(int k){
         if(size==capacity){
            //cout<<"Overflow"<<endl;
            return;
        }

        size++;
        int v=size-1;
        arr[v]=k;

        while(v!=0 && arr[parent(v)]<arr[v]){
            swap(&arr[v],&arr[parent(v)]);
            v=parent(v);
        }

    }

    void increaseKey(int v,int newVal){
        
        arr[v]=newVal;
         while(v!=0 && arr[parent(v)]<arr[v]){
            swap(&arr[v],&arr[parent(v)]);
            v=parent(v);
        }

        
    }

    int getMax(){
        return arr[0];
    }

    int removeMax(){
        if(size<=0)
        return INT_MIN;

        if(size==1){
            size--;
            return arr[0];
        }

        int root=arr[0];
        arr[0]=arr[size-1];
        size--;
        MaxHeapify(0);

        return root;
    }

    void deleteKey(int v){
        increaseKey(v,INT_MAX);
        removeMax();
    }

    void MaxHeapify(int v){
        int l=left(v);
        int r=right(v);

        int largest=v;

        if(l<size && arr[l]>arr[v])
        largest=l;

        if(r<size && arr[r]>arr[largest])
        largest=r;

        if(largest!=v){
            swap(&arr[v],&arr[largest]);
            MaxHeapify(largest);
        }
    }

    int curSize(){
        return size;
    }


 void swap(int *x,int *y){

    int temp=*x;
    *x=*y;
    *y=temp;
}




};

class Solution{
    
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int>ans;
	    MaxHeap h(n+5);
	    for(int i=0;i<n;i++){
	        h.insertKey(arr[i]);
	    }
	    
	    for(int i=0;i<k;i++){
	        ans.push_back(h.removeMax());
	    }
	    
	   // vector<int>temp;
	    
	   // for(int i=k;i<n;i++){
	   //     temp.push_back(h.removeMax());
	   // }
	    
	    return ans;
	    
	    
	}
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends