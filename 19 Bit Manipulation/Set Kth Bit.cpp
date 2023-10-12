#include <iostream>
#include<vector>
using namespace std;

int setKthBit(int n, int k){
    int mask = 1<<k;
    n = n | mask;
    return n;
}

int main(){
    int n=10;
    int k=2;
    int ans = setKthBit(n,k);
    cout<<"Answer is : "<<ans<<endl;
    return 0;
}