/*http://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */
// This function should return tree if passed  tree 
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree
bool isbalancedUtil(Node* root, int *h){
    int lheight,rheight;
    if(root==NULL){
        *h=0;
        return true;
    }
    bool lres = isbalancedUtil(root->left, &lheight);
    bool rres = isbalancedUtil(root->right, &rheight);
    *h = (max(lheight,rheight)) + 1;
    if(abs(lheight - rheight) <=1 && lres && rres)
        return true;
    return false;
}
bool isBalanced(Node *root)
{
    int ht;
    return isbalancedUtil(root,&ht);
}
