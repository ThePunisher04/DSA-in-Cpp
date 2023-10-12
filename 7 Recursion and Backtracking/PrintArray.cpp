#include <iostream>
using namespace std;

void print(int arr[], int n, int i) {
        //base case
        if( i >= n) {
                return;
        }

        //1 case solve krdia
        cout << arr[i] << "->";
        //baaki recursion sambhal lega
        print(arr, n, i+1);

}