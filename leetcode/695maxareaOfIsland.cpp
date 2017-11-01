//https://leetcode.com/problems/max-area-of-island/description/
class Solution {
public:
    int MARKER = -1;
    void dfs(vector<vector<int>>& grid, int i, int j, int &cnt, int &maxans){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size()|| grid[i][j]!=1 )
            return;
        
        if(grid[i][j]==1){
            grid[i][j]=-1;
            cnt+=1;
            maxans = max(maxans,cnt);
            vector<int> posx = {-1,0,0,1};
            vector<int> posy = {0,-1,1,0};
            for(int k=0;k<posx.size();k++){
                dfs(grid,posx[k]+i,posy[k]+j,cnt,maxans);
            }
        }
        
    } 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int cnt=0;
                if(grid[i][j]==1)
                    dfs(grid,i,j,cnt,maxans);
            }
        }
        return maxans;
    }
};