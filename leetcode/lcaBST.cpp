/** https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int n1 = p->val > q->val ? q->val:p->val;
        int n2 = p->val > q->val ? p->val:q->val;
        if(root->val>=n1 && root->val<=n2){
           return root;
        }
        if(root->val>n2 && root->val>n1)
            return lowestCommonAncestor(root->left,p,q);
        return lowestCommonAncestor(root->right,p,q);
    }
};