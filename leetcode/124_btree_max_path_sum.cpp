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
    int gMPS(TreeNode* root, int &maxi){
        if(root==NULL){ 
            return 0;
        }
        int lht,rht,in_node_l,in_node_r,lmax,rmax;
        lmax = gMPS(root->left,maxi);
        rmax = gMPS(root->right,maxi);
        if(lmax<0){
            lmax = 0;
        }
        if(rmax<0){
            rmax = 0;
        }
        if(lmax+rmax+root->val>maxi)
            maxi  = lmax+rmax+root->val;
        return root->val + max(lmax,rmax);
        // *in_node = max(in_node_l,in_node_r) + root->val;
        // *ht = max(lht,rht)+1;
        // int mv = max(max(*in_node,root->val),max(in_node_l+in_node_r+root->val, root->val));
        // return max(max(lmax,rmax), mv);
        
    }
    int checkTree(TreeNode* root, int &maxi, bool &pos){
        if(root==NULL)
            return 0;
        if(pos == false && root->val>0){
           pos = true; 
        }
        maxi = max(maxi, root->val);
        if(root->left)
            checkTree(root->left, maxi, pos);
        if(root->right)
            checkTree(root->left, maxi, pos);
        return maxi;
    }
    
    int maxPathSum(TreeNode* root) {
        // int ht,v;
        // int maxi=root->val;
        // bool pos=false;
        // checkTree(root,maxi,pos);
        // if(pos == false)
        //     return maxi;
        int maxi = INT_MIN;
         gMPS(root,maxi);
        return maxi;
    }
};