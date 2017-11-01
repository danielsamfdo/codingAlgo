// A C++ program to order of characters in an alien language
#include<iostream>
#include <list>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/
// #include<bits/stdc++.h>
/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/
class Graph{
    public:
    int V;
    list<int> *adj;
    string res;
    Graph(int alpha){
        this->V = alpha;
        adj = new list<int>[alpha];
        res = "";
    }
    
    void addEdge(int u, int v){
        adj[u].push_back(v);
    }
    void topsort(){
        vector<bool> visited(V, 0);
        for(int i=0;i<V;i++){
            if(!visited[i])
                topsortUtil(visited,i);
        }
    }
    
    void topsortUtil(vector<bool> &visited, int v){
        visited[v] = true;
        list<int>::iterator it=adj[v].begin();
        
        for(;it!=adj[v].end();it++){
            
            if(!visited[*it]){
                topsortUtil(visited, *it);
            }
        }
        res+= v+'a';

        //cout<<output<<" ";
    }
      
};

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */
string printOrder(string dict[], int N, int k)
{
    Graph g(k);
    for(int i=1;i<N;i++){
        for(int j=0;j<min(dict[i-1].size(),dict[i].size());j++){
            if(dict[i-1][j]!=dict[i][j]){
                g.addEdge(dict[i-1][j]-'a',dict[i][j]-'a');
                break;
                
            }
        }
    }
    g.topsort();
    //cout<<g.res;
    string result="";
    //cout << g.res<<endl;
    for(int i=g.res.size()-1;i>=0;i--){
        //cout<<g.res[i]<<"  ";
        result+=g.res[i];
    }
    //cout<<result<<endl;
    return result;
    //return reverse(g.res.begin(),g.res.end());
}
// Driver program to test above functions
int main()
{
  string words[] = {"baa", "abcd", "abca","cab", "cad"};//5 4
  cout<<printOrder(words, 5, 4);
  return 0;
}
