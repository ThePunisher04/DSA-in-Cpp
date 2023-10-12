//LC-273

// Convert a non-negative integer num to its English words representation.

// Example 1:
// Input: num = 123
// Output: "One Hundred Twenty Three"

// Example 2:
// Input: num = 12345
// Output: "Twelve Thousand Three Hundred Forty Five"

// Example 3:
// Input: num = 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

class Solution {
    //Time COmplexity -> O(log10(n))
        //TC is proportional to number of words generated
        //number of words generated is proportional to number of digits
        //one digit can be represented by at most two words
        //number of digits = ceil(log10(n))

    //Space COmplexity -> O(log10(n))
        //SC is proportioal to number of digits
public:
    
    vector<pair<int,string> > mp = {{1000000000,"Billion"},{1000000,"Million"},{1000,"Thousand"},{100,"Hundred"},{90,"Ninety"},{80,"Eighty"},{70,"Seventy"},{60,"Sixty"},{50,"Fifty"},{40,"Forty"},{30,"Thirty"},{20,"Twenty"},{19,"Nineteen"},{18,"Eighteen"},{17,"Seventeen"},{16,"Sixteen"},{15,"Fifteen"},{14,"Fourteen"},{13,"Thirteen"},{12,"Twelve"},{11,"Eleven"},{10,"Ten"},{9,"Nine"},{8,"Eight"},{7,"Seven"},{6,"Six"},{5,"Five"},{4,"Four"},{3,"Three"},{2,"Two"},{1,"One"}};
    
    string numberToWords(int num) {
        //base case
        if(num == 0){
            return "Zero";
        }
        
        //solve one case
        for(auto it : mp){
            if(num >= it.first){
                string a = "";
                if(num >= 100){
                    //kitne hundred, kitne thousand, kitne million
                    a = numberToWords(num / it.first) + " ";
                }
                string b = it.second;
            
                string c = "";
                if(num % it.first != 0){
                    c = " " + numberToWords(num % it.first);
                }

                return a + b + c;
                }
        }
        return "";
    }
};