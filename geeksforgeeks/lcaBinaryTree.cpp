/* http://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
bool v1=false;
bool v2=false;
Node * LCA(Node* root ,int n1 ,int n2 )
{
   if(root==NULL) return NULL;
   if(root->data==n1){
        v1=true;
        return root;
   }
   if(root->data==n2){
        v2=true;
        return root;
       
   }
   Node* l = LCA(root->left,n1,n2);
   Node* r = LCA(root->right,n1,n2);
   if(l && r)
        return root;
    if(l)
    return l;
    return r;
}