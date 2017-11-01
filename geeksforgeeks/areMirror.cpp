/* http://practice.geeksforgeeks.org/problems/two-mirror-trees/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b)
{
    if(a==NULL && b==NULL)
        return 1;
    if(a==NULL||b==NULL)
        return 0;
    if(a->data != b->data)
        return 0;
    return areMirror(a->left,b->right) & areMirror(a->right,b->left);
}
