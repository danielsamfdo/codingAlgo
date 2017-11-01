/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the tree is as
struct Node
{
  int key;
  struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not

bool checkSym(struct Node* a,struct Node* b){
    if(a==NULL && b==NULL)
        return true;
    if(a==NULL||b==NULL)
        return false;
    if(a->key==b->key)
        return checkSym(a->left,b->right) && checkSym(a->right,b->left);
    return false;
}
bool isSymmetric(struct Node* root)
{
     if(root==NULL) return true;
   return checkSym(root,root);
  
}