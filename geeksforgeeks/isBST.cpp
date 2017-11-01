/*  http://practice.geeksforgeeks.org/problems/check-for-bst/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
   
bool isBSTutil(Node* root, int lmin, int lmax){
    if(root==NULL)
        return true;
    if(root->data <lmin || root->data>lmax)
        return false;
    return isBSTutil(root->left, lmin, root->data) && isBSTutil(root->right, root->data+1, lmax);
}

bool isBST(Node* root) {
    return isBSTutil(root, INT_MIN, INT_MAX);
}
