#include <bits/stdc++.h> 

void reverse(string& str, int i, int j){
	if(i>j){
		return ;
	}

	swap(str[i],str[j]);
	i++;
	j--;

	reverse(str,i,j);
}

string reverseString(string str)
{
	// Write your code here.
	reverse(str,0,str.length()-1);
	return str;

}