//http://practice.geeksforgeeks.org/problems/sum-tree/1

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
int Sum(Node* root)
{
    if(root==NULL) return 0;
    return root->data + Sum(root->left) + Sum(root->right);
}
bool isSumTree(Node* root)
{//(root->left==NULL && root->right==NULL) is very imp. else Sum(root->left) +  Sum(root->right)  will be zero
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    return isSumTree(root->left) && isSumTree(root->right) && (Sum(root->left) +  Sum(root->right) == root->data);
     // Your code here
}