//https://leetcode.com/problems/n-queens/description/
class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col){
        for(int i=0;i<board.size();i++)
            if(board[row][i]!='.')
                return false;
        for(int i=0;i<board.size();i++)
            if(board[i][col]!='.')
                return false;
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
            if(board[i][j]!='.')
                return false;
        for(int i=row,j=col;i<board.size()&&j>=0;i++,j--)
            if(board[i][j]!='.')
                return false;
        return true;
    }
    void solveUtil(vector<vector<string>> &answer, vector<string> &board, int col){
        if(col>=board.size()){
            answer.push_back(board);
            //return true;
        }
        for(int i=0;i<board.size();i++){
            if(isSafe(board, i, col)){
                board[i][col]='Q';
                solveUtil(answer, board, col+1);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> Answer;
        vector<string> Board(n);
        string s="";
        for(int i=0;i<n;i++){
            s+=".";
        }
        for(int i=0;i<n;i++){
            Board[i] = s;
        }
        solveUtil(Answer,Board,0);
        return Answer;
    }
};