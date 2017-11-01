/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int widthOfBinaryTree(TreeNode* root)
    {
        if(root==NULL) return 0;
       queue<TreeNode*> q;
       queue<TreeNode*> t;
       int maxi = 1;
       bool unfinished = true;
       q.push(root);
        int m = -12132;
       while(unfinished){
           while(!q.empty()){
               TreeNode* n = q.front();
               
               TreeNode* NMarker = new TreeNode(m);
               q.pop();
               if(n->left)
                   t.push(n->left);
               else
                   t.push(NMarker);
               if(n->right)
                   t.push(n->right);
               else
                   t.push(NMarker);

           }
           int v = t.size();
           int c=0;
           int cnt=0;
           bool st = true;
           while(!t.empty()){
               
               
               //cout<<t.front()->val<< "   "<<cnt<<endl;
               
               if(st && t.front()->val!=m){
                   st=false;
                   c=0;

               }
               if(t.front()->val!=m)
                   cnt=c+1;
               if(st==false)
                q.push(t.front());
               c++;
               t.pop();
           }
           //cout<<cnt<<"COUNT"<<endl;
           maxi = max(cnt,maxi);
           if(st)
                unfinished = false;
       }
       return maxi;
    }

};