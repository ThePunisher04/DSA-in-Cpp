//GFG

//store the freq of each character in a hash table
//TC -> o(n)+O(n)=> O(n)
//SC -> O(n)

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int> hash;
        for(int i=0; i<n ; i++){
            hash[arr[i]]++;
        }
        for(int i=0 ; i<n ; i++){
            if(hash[arr[i]] > 1){
                return i+1;
            }
        }
        return -1;
    }
};