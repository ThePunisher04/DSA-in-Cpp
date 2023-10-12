#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Find the element in an infinite sorted array
//Array with only start but with no end
//Binary Search will fail here

//Brute Force
// 1,2,3,4,5,6,7,8.................................infinity 

int i=0;
while(true){
    if(arr[i] > x){
        break;
    }
    if(arr[i] == x){
        ans = i;
    }
    ++i;
}

//Better approach -> exp search

int i=0; //starting positon of the window
int j=1; //ending positon of the window
while(a[j] < x){
    i=j;
    j=j*2;
}
//now apply binary search with i as start and j as end