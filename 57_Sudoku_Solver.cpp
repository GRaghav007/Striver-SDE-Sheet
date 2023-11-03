class Solution {
private:
    bool solve(vector<vector<char> >& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                //If a vacant space is found,
                if(board[i][j] == '.'){
                    for(char num = '1'; num <= '9'; num++){
                        //Checking if it is safe to place 'num' in 'row-i' and 'col-j',
                        if(isSafe(board, i, j, num)){
                            board[i][j] = num;
                            if(solve(board) == true){   //If it returns true that means we have our sudoku has been solved.
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;   //When no number could be placed.
                }
            }
        }

        return true;
    }

    bool isSafe(vector<vector<char> > board, int row, int col, char num){
        for(int i = 0; i <= 8; i++){
            //Checking each column,
            if(board[row][i] == num)    return false;
            //Checking each row,
            if(board[i][col] == num)    return false;
            //checking the 3*3 sub-matrix,
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num)  return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};