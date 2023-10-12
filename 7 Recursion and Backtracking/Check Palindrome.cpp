bool isPalindrome(string& s, int start, int end){
    if(start >= end){
        return true;
    }

    if(s[start] != s[end]){
        return false;
    }

    isPalindrome(s, start+1, end-1);
}

//TC -> O(n/2 + 1) = O(n)
//SC -> O(n/2 + 1) = O(n)