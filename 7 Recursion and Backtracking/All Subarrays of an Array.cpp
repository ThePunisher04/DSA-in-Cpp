void printSubArray_util(vector<int>& nums, int start, int end){
    if(end >= nums.size()){
        return;
    }

    for(int i=start ; i<= end ; i++){
        cout<<nums[i]<<"";
    }
    cout<<endl;

    printSubArray_util(nums, start, end + 1);
}

void printSubArray(vector<int> nums){
    for(int start = 0 ; start < nums.size() ; start++){
        int end = start;
        printSubArray_util(nums, start, end);
    }
}


//Time complexity -> O(n2)
//Space complexity -> O(n+2) = O(n)