#include <bits/stdc++.h> 
using namespace std;

void display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    int i = n-1;
    int j = m-1;
    vector<int> result;
    
    int carry = 0;
    
    while(i>=0 && j>=0){
        int sum = a[i] + b[j] + carry;
        int ans = sum % 10;
        result.push_back(ans);
        carry = sum / 10;
        i--;
        j--;
    }
    while(i>=0){//first array is larger
        int sum = a[i] + carry;
        int ans = sum % 10;
        result.push_back(ans);
        carry = sum / 10;
        i--;
    }
    while(j>=0){//second array is larger
        int sum = b[j] + carry;
        int ans = sum % 10;
        result.push_back(ans);
        carry = sum / 10;
        j--;
    }
    while(carry != 0){//both arrays are of same size
        int sum = carry;
        int ans = sum % 10;
        result.push_back(ans);
        carry = sum / 10;
    }
    
    reverse(result.begin(),result.end());
    return result;
    
}

int main(){
    vector<int> arr1 = {2,3,4};
    vector<int> arr2 = {5,6};

    vector<int> arr3 = findArraySum(arr1,3,arr2,2);

    display(arr3);
}





// //CODE STUDIOS

// #include <bits/stdc++.h> 
// vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
// 	// Write your code here.
//     int i = n-1;
//     int j = m-1;
//     vector<int> result;
    
//     int carry = 0;
    
//     while(i>=0 && j>=0){
//         int sum = a[i] + b[j] + carry;
//         int ans = sum % 10;
//         result.push_back(ans);
//         carry = sum / 10;
//         i--;
//         j--;
//     }
//     while(i>=0){//first array is larger
//         int sum = a[i] + carry;
//         int ans = sum % 10;
//         result.push_back(ans);
//         carry = sum / 10;
//         i--;
//     }
//     while(j>=0){//second array is larger
//         int sum = b[j] + carry;
//         int ans = sum % 10;
//         result.push_back(ans);
//         carry = sum / 10;
//         j--;
//     }
//     while(carry != 0){//both arrays are of same size
//         int sum = carry;
//         int ans = sum % 10;
//         result.push_back(ans);
//         carry = sum / 10;
//     }
    
//     reverse(result.begin(),result.end());
//     return result;
    
// }