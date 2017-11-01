/* http://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
void hasPathUtil(Node* node, int sum, int curr_sum, bool &ans){
    if(ans){return;}
    if(node){
        if(node->left==NULL && node->right==NULL && curr_sum+node->data==sum){
            ans= true;
            return; 
        }
        hasPathUtil(node->left, sum, curr_sum+node->data, ans);            
        hasPathUtil(node->right, sum, curr_sum+node->data, ans);    
    }
}
bool hasPathSum(Node *node, int sum)
{
   bool ans=false;
   hasPathUtil(node->left,sum,node->data,ans);
   hasPathUtil(node->right,sum,node->data,ans);
   return ans;
}