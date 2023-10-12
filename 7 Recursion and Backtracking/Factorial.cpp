#include <iostream>
using namespace std;

int factorial(int n){
    if (n==0){
        return 1;
    }

    return n * factorial(n-1);
}

int main(){
    int n = 7;
    int fact = factorial(n);
    cout<<"Factorial is : "<<fact<<endl;
    return 0;
}