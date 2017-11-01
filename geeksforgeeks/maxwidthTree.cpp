/*http://practice.geeksforgeeks.org/problems/maximum-width-of-tree
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Structure of a Binary Tree 
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(root==NULL) return 0;
   queue<Node*> q;
   queue<Node*> t;
   int maxi = 1;
   bool unfinished = true;
   q.push(root);
   while(unfinished){
       while(!q.empty()){
           Node* n = q.front();
           q.pop();
           if(n->left)
               t.push(n->left);
           if(n->right)
               t.push(n->right);
           
       }
       int v = t.size();
       maxi = max(v,maxi);
       while(!t.empty()){
           q.push(t.front());
           t.pop();
       }
       if(q.empty())
            unfinished = false;
   }
   return maxi;
}
