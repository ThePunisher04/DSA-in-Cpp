// LC-658

// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b



//SORTED word sunke 2 baat yaad aati hai -> Binary Search and Two-Pointer



// Approach-1
// har element se x ka difference nikal lo and then array ko difference ke base pe sort kardo
// fir first k elements return kardo
// TC -> O(n*logn)



//Approach-2 : SLIDING WINDOW -> Two Pointer
//Low and High 2 pointer rakh lo at index 0 and index size-1 respectively
//ab mujhe apne k-closest elements to saaf saaf dikh hi rahe hai paper pe, to kyu na low ko aage badha ke and high ko kam karke unn k-closest elements ke pass pahunch jaye
//fir ek loop laga ke low to high tak traverse karlo

//agar low vala element bada hai to use aage move krdo kyuki aage diff kam hoga
//agar high vala element bada hai to use piche move krdo kyuki piche diff kam hoga
//hume k-closest elements vali window pe pahunchna hai
//bada diff vala element lene se koi fayda nahi hai isiliye hum har baari chote diff vale element ki taraf move kar rahe hai
//jab high - low ka diff k ke barabar ho jaye tab apna loop rok dena

//Time complexity -> window ka size pehle n tha , par ab k ho gaya, n->k jane mein hume total (n-k) comparisons karne padenge
//iss approach mein window size ko kam kar rahe hai
// O(n-k) => O(n)
class Solution {
public:
    vector<int> twoPointer(vector<int>& arr, int k, int x){
        int low=0;
        int high=arr.size()-1;
        
        while(high-low >= k){
            if(x - arr[low] > arr[high] - x){
                low++;
            }
            else{
                high--;
            }
        }
        vector<int> ans;
        for(int i=low; i<=high ; i++){
            ans.push_back(arr[i]);
        }
        return ans;

        // OR
        // return vector<int> (arr.begin() + low, arr.begin() + high + 1);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointer(arr,k,x);
    }
};



// Approach-3 : BINARY SEARCH + Two-Pointer 
// steps:-
// 1) find smallest element in the arr which is >= x
//         lower bound -> closest element to x
// 2) set high = index of closest element (the element which has diff=0)
// 3) set low = high - 1 
//             kyuki low hamesha high se piche hi rahega
//4) [low -> high] vali window form karunga jiska size k ke barabar hoga (expand karna h)

//previous approach se ekdum ulta kaam kar rahe hai
//low and high mei se jonsa bhi chota hoga usko shift karunga
//agar high chota hai to high++
//agar low chota hai to low--
//low aur high jis element pe point kar rahe honge unko chor ke, unke beech vale element k-closest elements honge
//total k comparisons honge

int lowerBound(vector<int>& arr, int x){
    int start = 0;
    int end = arr.size() - 1;
    int ans = end;

    while(start <= end){
        int mid = start +(end - start) / 2;
        if(x == arr[mid]){
            ans = mid;
            end = mid-1;
        }
        else if(x > arr[mid]){
            start = mid+1;
        }
        else{
            end=mid-1;
        }
    }

    return ans;
}

vector<int> binarySearch(vector<int>& arr, int k, int x){
    //lower bound
    int high = lowerBound(arr, x);
    int low = high - 1;

    while(k--){
        if(low<0){
            high++;
        }
        else if(high>=arr.size()){
            low--;
        }
        else if(x - arr[low] > arr[high] - x){
            high++;
        }
        else{
            // x - arr[low] < arr[high] - x 
            low--;
        }
    }

    return vector<int> (arr.begin() + low + 1, arr.begin() + high);
}

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return binarySearch(arr, k, x);
}