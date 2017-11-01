/* http://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */
// Should set the nextRight for all nodes
void connect(Node *p)
{
    queue<Node*> q;
    queue<Node*> t;
    bool unfinished=true;
    q.push(p);
    while(unfinished){
    Node * prev= NULL;
    while(!q.empty()){
        Node* n = q.front();
        q.pop();
        if(n->left)
            t.push(n->left);
        if(n->right)
            t.push(n->right);
        
        if(prev)
            prev->nextRight = n;
        prev = n;
        n->nextRight=NULL;
    }
    while(!t.empty()){
        q.push(t.front());
        t.pop();
    }
    if(q.empty())
        unfinished=false;
    }
}
