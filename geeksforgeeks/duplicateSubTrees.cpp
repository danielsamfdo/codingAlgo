/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/



/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
string dupSubUtil(Node * root, bool &ans,unordered_set<string> &subtrees){
    string s= "";
    string marker = "*";
    if(root==NULL){
        return s+marker;
    }
    string l = dupSubUtil(root->left,ans,subtrees);
    string r = dupSubUtil(root->right,ans,subtrees);
    s = l+root->data+r;
    if(s.size()>3 && subtrees.find(s)!=subtrees.end()){
        ans = true;
        
    }else
        subtrees.insert(s);
    return s;
    
}

bool dupSub(Node *root)
{
    bool ans = false;
    unordered_set<string> subtrees;
    dupSubUtil(root,ans,subtrees);
    return ans;
}