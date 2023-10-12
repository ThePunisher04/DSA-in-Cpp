//LC-85
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area. 

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.


class Solution {
public:

    
int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    std::stack<int> stk;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        while (!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
            int height = heights[stk.top()];
            stk.pop();

            int width = stk.empty() ? i : i - stk.top() - 1;
            maxArea = std::max(maxArea, height * width);
        }
        stk.push(i);
    }

    return maxArea;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = std::max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
    }
};