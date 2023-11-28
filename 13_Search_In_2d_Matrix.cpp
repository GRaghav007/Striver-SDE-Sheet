    class Solution {
private:
    bool search(vector<vector<int>>& matrix, int row, int target){
        int beg = 0, end = matrix[row].size()-1;
        while(beg <= end){
            int mid = beg + (end-beg)/2;
            if(matrix[row][mid] == target)  return true;
            else if(matrix[row][mid] < target)  beg = mid+1;
            else    end = mid-1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()/2;
        do{
            if(matrix[row][0] == target)    return true;
            if(matrix[row][0] > target) row--;
            else if(matrix[row][0] < target){
                if(row + 1 < matrix.size()){
                    if(matrix[row+1][0] > target)   return search(matrix, row, target);
                    else    row++;
                } 
                else    return search(matrix, row, target);
            }
        }while(row >= 0 && row < matrix.size());

        return false;
    }
};