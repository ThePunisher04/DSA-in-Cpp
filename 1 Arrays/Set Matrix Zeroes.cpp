class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> zeroes;

        for(int i=0 ; i<rows; i++){
            for(int j=0 ; j<cols ;j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i,j});
                }
            }
        }

        for(auto ele : zeroes){
            int rowNumber = ele.first;
            int columnNumber = ele.second;

            for(int j = 0 ; j < cols ; j++){
                matrix[rowNumber][j] = 0;
            }
            for(int j = 0 ; j < rows ; j++){
                matrix[j][columnNumber] = 0;
            }
        }
    }
};