#include <bits/stdc++.h> 
#include <vector>
using namespace std;

//QuickSort is made up of 2 things
//Partition logic and Recursive Logic

//Partition logic
    //choose an element as pivot
    //place this pivot element to its correct position
            //count how many numbers are smaller than pivot
            //swap(arr[pivotIndex], arr[start + count])
    //make sure that all the smaller elements than pivot come to the left side of the pivot, while all the greater elements than pivot come to the right side of the pivot
            //use two pointer -> place i at starting index and j at ending index
            //compare i and j with pivotIndex
            //while i is smaller or equal to pivot, increment i
            //while j is greater than pivot, decrement j
            //if i is greater than pivot and j is smaller than pivot, swap i and j
    //now call the recursive function

int partition(vector<int>& arr, int s, int e)
{
    //taking starting element as pivot
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part smbhal lete h
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        //2 cases
        //CASE A => wrong elements found at both ends
        // CASE B => out of bound from both side 
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void solve(vector<int>& arr, int s, int e)
{

    // base case
    if (s >= e)
        return;

    // partitioon karenfe
    int p = partition(arr, s, e);

    // left part sort karo
    solve(arr, s, p - 1);

    // right wala part sort karo
    solve(arr, p + 1, e);
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    solve(arr,0,arr.size()-1);
    return arr;
}
