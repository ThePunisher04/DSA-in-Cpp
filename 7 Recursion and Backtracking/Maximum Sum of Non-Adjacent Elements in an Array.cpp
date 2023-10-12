void maxSumNonAdj(vector<int> &nums, int i, int sum, int &maxi){
    if(i >= nums.size()){
        maxi = max(maxi, sum);
        return;
    }

    //include 
    maxSumNonAdj(nums, i + 2, sum + nums[i], maxi);

    //exclude
    maxSumNonAdj(nums, i + 1, sum + 0, maxi);
}