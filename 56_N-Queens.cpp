class Solution {
private:

    bool isSafe(int row, int col, vector<string> board, int n){
        int dupRow = row, dupCol = col;
        
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')  return false;
            row--;
            col--;
        }

        //Checking left side,
        row = dupRow, col = dupCol;
        while(col >= 0){
            if(board[row][col] == 'Q')  return false;
            col--;
        }

        //Checking lower diagonal,
         row = dupRow, col = dupCol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q')  return false;
            row++;
            col--;
        }

        return true;
    }

    void solveMoreTime(int col, vector<string> board, vector<vector<string> > &ans, int n){
        //Base Case,
        if(col >= n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q'; 
                solveMoreTime(col+1, board, ans, n); 
                board[row][col] = '.'; 
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string x(n, '.');
        vector<string> board;
        vector<vector<string> > ans;
        for(int i = 0; i < n; i++){
            board.push_back(x);
        }

        solveMoreTime(0, board, ans, n);

        return ans;
    }
};