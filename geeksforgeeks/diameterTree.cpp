/* http://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Computes the diameter of binary tree with given root.  */
int diameterUtil(Node* node, int *h){
    if(node==NULL){
        *h = 0;
        return 0;
    }
    int lh,rh;
    int ld,rd;
    ld = diameterUtil(node->left, &lh);
    rd = diameterUtil(node->right, &rh);
    *h = max(lh,rh) + 1;
    return max(lh+rh+1,max(ld,rd));
}
int diameter(Node* node)
{
   int h;
   return diameterUtil(node, &h);
}