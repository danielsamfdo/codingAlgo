class Solution {
public:
    void addToList(unordered_map<string, vector<int>> &wildcard, string word, int index){
        for(int i=0;i<=word.size()-1;i++){
            wildcard[word.substr(0,i) + '_' + word.substr(i+1)].push_back(index);
        }
    }
    int getLLeng(unordered_map<string, vector<int>> &wildcard, string word, string dest, vector<string>& wordList, unordered_map<string, bool> &visited){
        if(word==dest)
            return 0;
        
        queue<string> q,t;
        q.push(word);
        int length = 0;
        while(!q.empty()){
            while(!q.empty()){
                word = q.front();
                q.pop();
                //cout<<word<<endl;
//                 if(visited.find(word)!=visited.end()){
//                     visited[word] = true;
                    
//                 }
                if(word==dest)
                    return length;
                if(!visited[word]){
                    visited[word] = true;
                    //cout<<word<<"  "<<visited[word]<<endl;
                    for(int i=0;i<=word.size()-1;i++){
                        vector<int> res = wildcard[word.substr(0,i) + '_' + word.substr(i+1)];
                        for(int j=0;j<res.size();j++){
                            if(!visited[wordList[res[j]]]){
                                t.push(wordList[res[j]]);
                            }
                        }
                    }
                }
                

            }
            length++;
            while(!t.empty()){
                q.push(t.front());
                t.pop();
            }
        }
        return -1;
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<int>> wildcard(wordList.size());
        unordered_map<string, bool> visited;
        
        for(int i=0;i<wordList.size();i++){
            visited[wordList[i]] = false;
            addToList(wildcard, wordList[i],i);
        }
        visited[beginWord] = false;
//         for(unordered_map<string, vector<string>>::iterator it = wordList.begin();it!=wordList.end();it++){
//             cout<<it->first << "  " << endl;
//             vector<string> res = it->second;
            
//         }
        for (auto& p : wildcard)
        {
            std::string const& key = p.first;
            // ...

            std::vector<int>& res = p.second;
            // for(int i=0;i<res.size();i++){
            //     cout<< wordList[res[i]]<<"  ";
            // }
        }
        
        return getLLeng(wildcard, beginWord, endWord,wordList,visited)+1;
    }
};