void removeOcc(string& s, string& part){
    int found = s.find(part);
    if(found != string::npos){
        string left_part = s.substr(0,found);
        string right_part = s.substr(found + part.length(), s.length());
        s = left_part + right_part;
    }
    else{
        //base case
        return;
    }
}

string removeOccurences(string s, string part){
    removeOcc(s,part);
    return s;
}

//Time complexity 
    //find = O(n*m)
    //leftPart = O(n)
    //rightPart = O(n)
    //concat = O(n)
    //overall = O(n*m)

    //total calls in worst case
    //"abcabcabcabcabcabc"    s.length = 18      part.length = 3
    //calls = 18/3 = 6 => O(n/m)
    //therefore, TC = > O(n/m  *  n*m)  => O(n2)

//Space complexity
    //O(n/m)