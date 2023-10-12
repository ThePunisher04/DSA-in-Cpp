//LC-1878

// You are given an m x n integer matrix grid​​​.

// A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


// Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

// Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

// Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
// Output: [228,216,211]
// Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
// - Blue: 20 + 3 + 200 + 5 = 228
// - Red: 200 + 2 + 10 + 4 = 216
// - Green: 5 + 200 + 4 + 2 = 211


class Solution {
public:
    bool checkBounds(vector<vector<int>>& grid, vector<pair<int, int>>& v){
        int m = grid.size();
        int n = grid[0].size();

        for(auto pt : v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
                return false;
            }
        }
        return true;
    }

    bool getAllVertices(vector<vector<int>>& grid, vector<pair<int, int>>& v, pair<int, int> p, int& delta){
        pair<int, int> A(p.first - delta, p.second);
        pair<int, int> B(p.first, p.second + delta);
        pair<int, int> C(p.first + delta, p.second);
        pair<int, int> D(p.first, p.second - delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        if(checkBounds(grid, v)){
            return true;
        }
        return false;
    }

    void getAllSum(vector<vector<int>>& grid, int& cx, int& cy, priority_queue<int>& pq){
        //push rhombus sum of rhombus with area 0
        pq.push(grid[cx][cy]);
        int delta = 1;
        vector<pair<int, int>> v(4);
        while(getAllVertices(grid, v, {cx, cy}, delta)){
            pair<int,int>& A = v[0];
            pair<int,int>& B = v[1];
            pair<int,int>& C = v[2];
            pair<int,int>& D = v[3];
            int csum = grid[A.first][A.second] + grid[B.first][B.second] + 
                        grid[C.first][C.second] + grid[D.first][D.second];
            
            //all cells between A and B
            for(int i = 1 ; i < (B.first - A.first) ; i++){
                csum += grid[A.first + i][A.second + i];
            }

            //all cells between B and C
            for(int i = 1 ; i < (C.first - B.first) ; i++){
                csum += grid[B.first + i][B.second - i];
            }

            //all cells between C and D
            for(int i = 1 ; i < (C.first - D.first) ; i++){
                csum += grid[C.first - i][C.second - i];
            }

            //all cells between D and A
            for(int i = 1 ; i < (D.first - A.first) ; i++){
                csum += grid[D.first - i][D.second + i];
            }

            pq.push(csum);
            ++delta;
        }
    }

    bool canPush(vector<int>& ans, int& top){
        for(auto val : ans){
            if(val == top){
                return false;
            }
        }
        return true;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int> pq;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                getAllSum(grid, i, j, pq);
            }
        }

        while(!pq.empty() && ans.size() < 3){
            int top = pq.top();
            pq.pop();
            if(canPush(ans, top)){
                ans.push_back(top);
            }
        }
        return ans;
    }
};