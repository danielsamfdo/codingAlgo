//http://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/

/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
The structure of a BST node is as follows:
struct Node {
int data;
Node * right, * left;
};
*/
int getCountOfNode(Node *root, int l, int h)
{
  if(root==NULL)
  return 0;
  if(root->data>=l && root->data<=h){
      return 1+getCountOfNode(root->left,l,h)+getCountOfNode(root->right,l,h);
  }
  if(root->data>h){
      return getCountOfNode(root->left,l,h);
  }
  if(root->data<l){
      return getCountOfNode(root->right,l,h);
  }
}