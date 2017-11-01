#define asize 26;
class Solution {
public:
    struct TrieNode{
        bool isEnd;
        struct TrieNode* children[26];
        
    };
    struct TrieNode* getNode(){
        TrieNode* p = new TrieNode();
        for(int i=0;i<26;i++){
            p->children[i] = NULL;
        }
        p->isEnd = false;
        return p;
    }
    bool search(TrieNode* root, string s){
        TrieNode* pCrawl = root;
        for(int i=0;i<s.size();i++){
            if(pCrawl->children[s[i]-'a']==NULL)
                return false;
                
            pCrawl = pCrawl->children[s[i]-'a'];
        }
        return pCrawl!=NULL && pCrawl->isEnd;
    }
    
    TrieNode* psearch(TrieNode* root, string s){
        TrieNode* pCrawl = root;
        for(int i=0;i<s.size();i++){
            if(pCrawl->children[s[i]-'a']==NULL)
                return NULL;
                
            pCrawl = pCrawl->children[s[i]-'a'];
        }
        return pCrawl;
    }
    
    void insert(TrieNode* root, string s){
        TrieNode* pCrawl = root;
        for(int i=0;i<s.size();i++){
            if(pCrawl->children[s[i]-'a']==NULL)
                pCrawl->children[s[i]-'a'] = getNode();
            pCrawl = pCrawl->children[s[i]-'a'];
        }
        pCrawl->isEnd = true;
    }
    vector<int> posx = {-1,1,0,0};
    vector<int> posy = {0,0,-1,1};
    
    void getWords(int i, int j, vector<vector<char>>& board, vector<string> &res, unordered_map<string,bool> &word_collected, TrieNode* root, string s,vector<vector<bool>> &visited){
        if(i<0 || j<0 || i>=board.size()||j>=board[0].size()||visited[i][j])
            return;
        s+=board[i][j];
        visited[i][j] = true;
        TrieNode* p = psearch(root,s);
        if(p!=NULL){
            if(p->isEnd && word_collected.find(s)==word_collected.end()){
                word_collected[s] = true;
                res.push_back(s);
            }
            
            for(int k=0;k<8;k++)
                getWords(i+posx[k],j+posy[k],board,res, word_collected, root, s, visited);
        }
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = getNode();
        vector<string> res;
        unordered_map<string,bool> word_collected;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for(int i=0;i<words.size();i++){
            insert(root, words[i]);
        }
        // for(int i=0;i<words.size();i++){
        //     cout<<search(root, words[i]);
        // }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                getWords(i,j,board,res,word_collected,root,"", visited);
            }
        }
        
        return res;
    }
};