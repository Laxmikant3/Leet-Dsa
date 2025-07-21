class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();

        int rowIdx = 0;
        int colIdx = col-1;
        while ( rowIdx < row && colIdx>=0){
            int element = matrix[rowIdx][colIdx] ;
            if(element == target){
                return 1;

            }
            if(element < target){
                rowIdx++;
            }
            else{
                colIdx--;
            }
            
        }
        return 0;
    }
};