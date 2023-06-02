//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    public:
    int k=0;
    Node* bt(int  in[] , int pre[], int left, int right)
    {
        if(left>right)
        {
            return NULL;
        }
        Node* root = new Node (pre[k]);
        k++;
        int i;
        for(int j=left;j<=right;j++)
        {
            if(in[j]== root->data)
            {
                i=j;
                break;
            }
        }
        
        root->left = bt( in ,  pre, left, i-1);
        root->right = bt( in ,  pre, i+1, right);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* ans=  bt(in, pre, 0, n-1);
        return ans;
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends