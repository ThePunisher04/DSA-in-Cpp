#include <vector>
#include <iostream>
using namespace std;

void displayArray(vector<int> &arr)
{
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

vector<int> findMissingElement(vector<int> &arr)
{
    vector<int> ans;
    // Visited Method (Negative Marking)
    for (int i = 0; i < arr.size(); i++)
    {
        int index = abs(arr[i]);
        if (arr[index - 1] > 0)
        {
            arr[index - 1] *= -1;
        }
    }
    displayArray(arr);
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i] > 0){
            ans.push_back(i+1);
        }
    }
    return ans;
}

vector<int> findMissingElement2(vector<int> &arr){
    //Sorting + Swapping Method
    vector<int> ans;
    int i = 0;
    while(i < arr.size()){
        int index = arr[i] - 1;
        if(arr[index] != arr[i]){
            swap(arr[index], arr[i]);
        }
        else{
            ++i;
        }
    }
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] != i + 1){
            ans.push_back(i + 1);
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 3, 5, 3, 4, 6, 7, 7, 7, 5};
    vector<int> ans = findMissingElement2(v);
    cout << "The missing elements are : " << endl;
    displayArray(ans) ;
    cout << endl;
    return 0;
}