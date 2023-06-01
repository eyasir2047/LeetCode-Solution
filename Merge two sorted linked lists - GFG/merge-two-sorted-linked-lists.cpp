//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 



 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* head=head1;
    
    Node* temp1=head1;
    Node* temp2=head2;
    
    Node* temp=head1;
    
    //finding the smallest element and seting the head;
    if((head1->data)> (head2->data))
    {
        head=head2; 
        temp2=temp2->next;
        temp=head2;
    }
    else 
    {
        head=head1;
        temp=head1;
       temp1=temp1->next;
    }
    

    //cheking and adding elment in the head;
    while(temp1!=NULL && temp2!=NULL)
    {
        if((temp1->data)<(temp2->data))
        {
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
            
        }
        
        else
        {
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
            
    }
    
    
    //adding remaining element of temp1;
    while(temp1!=NULL)
    {
        temp->next=temp1;
        temp=temp1;
        temp1=temp1->next;
        
    }
    
    //adding remaining element of temp2;
    while(temp2!=NULL)
    {
        
        temp->next=temp2;
        temp=temp2;
        temp2=temp2->next;
    }
    
    
   
    
    return head;
    
    
}  