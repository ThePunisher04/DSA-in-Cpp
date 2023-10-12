//left to right

void lastOccLTR(string& s, char x, int i, int& ans){
    if(i >= s.length()){
        return;
    }

    if(s[i] == x){
        ans = i;
    }

    lastOccLTR(s, x, i+1, ans);
}


//right to left
void lastOccRTL(string& s, char x, int i, int& ans){
    if(i < 0){
        return;
    }

    if(s[i] == x){
        ans = i;
        return;
    }

    lastOccRTL(s, x, i-1, ans);
}