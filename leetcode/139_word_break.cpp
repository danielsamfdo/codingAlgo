#define asize 26
class Solution {
public:
    struct TrieNode{
        public:
        bool isEnd;
        struct TrieNode* children[26];
    };
    
    struct TrieNode* getNode(){
        struct TrieNode* p = new TrieNode();
        for(int i=0;i<asize;i++){
            p->children[i] = NULL;
        }
        p->isEnd=false;
        return p;
    }
    
    void insert(TrieNode* root, string s){
        struct TrieNode* pCrawl = root;
        for(int j=0;j<s.size();j++){
            if(pCrawl->children[s[j]-'a']==NULL){
                pCrawl->children[s[j]-'a'] = getNode();
            }
            pCrawl = pCrawl->children[s[j]-'a'];
        }
        pCrawl->isEnd = true;
    }
    
    bool search(TrieNode* root, string s){
        struct TrieNode* pCrawl = root;
        for(int j=0;j<s.size();j++){
            if(pCrawl->children[s[j]-'a']!=NULL)
                pCrawl = pCrawl->children[s[j]-'a'];
            else
                return false;
        }
        return pCrawl!=NULL && pCrawl->isEnd;
    }
    
    bool WB(TrieNode* rt, string s){
        if(search(rt,s))
            return true;
        for(int j=1;j<s.size();j++){
            string sub = s.substr(0,j);
            string rem = s.substr(j);
            //cout<<sub<<"  " << rem<<endl;
            if(search(rt,sub) && WB(rt, rem)){
                return true;
            }
        }
        return false;
    }
    
    bool WBDP(TrieNode* rt, string s){
        vector<bool> dp(s.size()+1, false);
        dp[0]=1;
        for(int i=1;i<=s.size();i++)
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string sub = s.substr(j,i-j);
                    if(search(rt,sub)){
                        dp[i] = true;
                        break;
                    }   
                }            
        }
        return dp[s.size()];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = getNode();
        for(int i=0;i<wordDict.size();i++){
            insert(root, wordDict[i]);
        }
        
        return WBDP(root, s);
    }
};