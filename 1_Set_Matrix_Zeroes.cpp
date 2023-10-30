class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row, col;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        vector<int>::iterator it1, it2;

        for(int i = 0; i < matrix.size(); i++){
            it1 = find(row.begin(), row.end(), i);
            if(it1 != row.end()){
                for(int j = 0; j < matrix[i].size(); j++){
                    matrix[i][j] = 0;
                }
            }

            else{
                for(int j = 0; j < matrix[i].size(); j++){
                    it2 = find(col.begin(), col.end(), j);
                    if(it2 != col.end()) matrix[i][j] = 0;   
                }
            }
        }
    }
};