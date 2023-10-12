#include <bits/stdc++.h> 
using namespace std; 

//GFG

// Intuition:-
//Approach1 : REVERSE TWO POINTER
//Time complexity -> O(n)
//Space Complexity -> O(1)
// both the arrays are sorted ,so take advantage of it
// take a left pointer for traversing arr1 from back (last index)
// take a right pointer for traversing arr2 from front (first index)
// if you find an element in arr1 which is greater than the element in the arr2, swap it
// else break

class Solution{
    public:
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int left  = n-1;
            int right = 0;
            
            while(left >= 0 && right < m){
                if(arr1[left] > arr2[right]){
                    swap(arr1[left], arr2[right]);
                    left--;
                    right++;
                }
                else{
                    break;
                }
            }
            
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};

//Approach - 2 : GAP METHOD


#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:      
        
        void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2){
            if(arr1[ind1] > arr2[ind2]){
                swap(arr1[ind1], arr2[ind2]);
            }
        }
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        {  
            int totalLength = n + m;
            int gap = totalLength/2 + totalLength%2;
        
            while(gap > 0){
                int left = 0;
                int right = left + gap;
                
                while(right < totalLength){
                    //arr1 and arr2
                    if(left < n && right >= n){
                        swapIfGreater(arr1, arr2, left, right - n);
                    }
                    //arr2 and arr2
                    else if(left >= n){
                        swapIfGreater(arr2, arr2, left - n, right - n);
                    }
                    //arr1 and arr1
                    else{
                        swapIfGreater(arr1, arr1, left, right);
                    }
                    left++;
                    right++;
                }
                if(gap == 1) break;
                gap = gap/2 + gap%2;
        
            }
        } 
};
