class Solution {
public:
    
    vector<vector<string>> solution;
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(board,0);
        return solution;
    }
    
    bool isSafe(vector<string> &board, int row, int col) {
	    int sz = board.size();
	    for(int i = 0; i < sz; i++) {
		    if(board[i][col] == 'Q') return false;
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  sz && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }
    
    void solve(vector<string> &board, int row){
        if(row == board.size()){
            solution.push_back(board);
            return;
        }
        
        for(int col = 0; col < board.size(); col ++){
            if(isSafe(board, row,col)){
                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.';
            }
        }
    }
};