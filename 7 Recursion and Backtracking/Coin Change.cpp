#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

//agar base case ki return statement likhni h, to function karta kya hai vo pata hona chahiye

int solve(vector<int>& arr, int target) {
  //base case
  if(target == 0) {
    return 0;
  }
  if(target < 0) {
    //invalid value ban gayi hai, mujhe yahan mini ko update nahi karna
    return INT_MAX;
  }

  //let's solve 1 case
  //har ek target ke liye, array mei jtine bhi element hai utni call ja rahi h
  int mini = INT_MAX;
  for(int i=0; i<arr.size(); i++) {
    int ans = solve(arr, target - arr[i]);
    if(ans != INT_MAX)
        mini = min(mini, ans + 1);
  }

  return mini;

}

int main() {
  vector<int> arr{1,2};
  int target = 5; 

  int ans = solve(arr, target);
  cout << "Answer is: " << ans << endl;
  return 0;
}