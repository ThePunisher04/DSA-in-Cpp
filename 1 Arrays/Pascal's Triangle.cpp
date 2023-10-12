class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;

        for(int i = 3 ; i <= numRows ; i++){
            vector<int> temp;
            temp.push_back(1);
            vector<int> lastVector = ans.back();
            for(int j=0 ; j<lastVector.size()-1 ; j++){
                int num = lastVector[j] + lastVector[j+1];
                temp.push_back(num);
            }
            temp.push_back(1);
            ans.push_back(temp);

        }

        return ans;
    }
};