// LC-48

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int rowIndex = 0; rowIndex < n ; rowIndex++){
            for(int colIndex = 0 ; colIndex < rowIndex ; colIndex++){
                swap(matrix[rowIndex][colIndex], matrix[colIndex][rowIndex]);
            }
        }

        for(int i=0 ; i< n ;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//code studio

void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n = mat.size();
	for(int i=0 ; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			swap(mat[i][j], mat[j][i]);
		}
	}

	for(int i=0; i<n; i++){
		reverse(mat[i].begin(), mat[i].end());
	}
	
}