//LC-1207

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

class Solution {
    
public:
    
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq;
        int size = arr.size();
        sort(arr.begin(),arr.end());
        int i = 0;
        while(i<size){
            int count = 1;
            for(int j =i+1 ; j<size ; j++){
                if(arr[i]==arr[j]){
                    count++;
                }
                else{
                    break;
                }
            }
            freq.push_back(count);
            i+=count;
        }
        sort(freq.begin(),freq.end());
        for(int i=0; i<freq.size(); i++){
            if(i+1<freq.size()){
                if(freq[i]==freq[i+1]){
                    return 0;
                }
            }
        }
        return 1;
    }
};