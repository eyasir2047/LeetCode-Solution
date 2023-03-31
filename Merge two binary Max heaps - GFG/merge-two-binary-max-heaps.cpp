//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
            cout<<"Overflow"<<endl;
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
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        MaxHeap h(n+m+5);
        for(int i=0;i<n;i++){
            h.insertKey(a[i]);
        }
        for(int j=0;j<m;j++){
            h.insertKey(b[j]);
        }
        
        vector<int>ans(n+m,0);
        for(int i=0;i<n+m;i++){
           ans[i]=h.removeMax();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends