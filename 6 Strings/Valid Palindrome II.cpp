// LC-680

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.


//TC -> O(n2)
class Solution {
public:
    bool checkPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        
        while(i<=j){
            if(s[i]!=s[j]){
                //dono ko ek ek baar remove karke check karo
                //agar i vala char remove kar rahe ho to (i+1,j) vali string check karo
                //agar j vala char remove kar rahe ho to (i,j-1) string check karo
                return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
            }
            else{
                // s[i]!=s[j]   ->  sab badhiya chal raha hai, aage badh jao
                i++;
                j--;
            }
        }
        //agar ye while loop pura chal gaya, to iska matlab ye string already ek palindrome tha
        return true;
    }
};