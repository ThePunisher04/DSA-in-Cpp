#include <iostream>
using namespace std;

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return fib(n-1) + fib(n-2);
}

int main(){
    int n = 8;
    int ans = fib(n);
    cout<<"The "<<n<<"th"<< " fibonacci number is : "<<ans<<endl;
    return 0;
}