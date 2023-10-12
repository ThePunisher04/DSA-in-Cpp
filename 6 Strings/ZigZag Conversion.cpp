// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"



// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"


//INTUITION:-
//if numRows = 1, return original string
//change direction after sometime
        //sabse pehle to hum numRows baar hi chalenge, fir direction reverse (Top -> Bottom)
        //then har numRows - 1 baar pe direction change kar denge (Bottom -> Top && Top -> Bottom) switch karna hai

//catch
        //direction change
        //base condition 
        //loop kitni baar chalana h


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<string> zigzag(numRows);
        
        int i=0, row=0;
        bool direction = 1;
        
        while(true){
            if(direction){
                while(row < numRows && i < s.size()){
                    zigzag[row].push_back(s[i]);
                    row++;
                    i++;
                } 
                row = numRows-2;
            }
            else{
                while(row >= 0 && i < s.size()){
                    zigzag[row].push_back(s[i]);
                    row--;
                    i++;
                }
                row=1;
            }
            if(i >= s.size())
                break;
            
            direction = !direction;
        }
        string ans="";
        
        for(int i=0 ; i<zigzag.size() ; i++){
            ans += zigzag[i];
        }
        
        return ans;
    }
};