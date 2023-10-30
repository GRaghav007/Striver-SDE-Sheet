class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int> > res = matrix;
        int i = 0, j = 0;
        int row = res.size(), col = res[0].size();

        for(int x = 0; x < col; x++){
            for(int y = row-1; y >= 0; y--){
                matrix[i][j++] = res[y][x];
            }
            i++;
            j = 0;
        }

        return;
    }
};