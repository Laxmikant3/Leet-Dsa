class Solution {
public:
    string longestNiceSubstring(string s) {
       if( s.length()<2) return "";

       unordered_set<char> char_set(s.begin(),s.end());
       for(int i=0;i<s.length();i++){
        if((char_set.count(tolower(s[i]))) && char_set.count(toupper(s[i]))) continue;
        string left=longestNiceSubstring(s.substr(0,i) );
        string right=longestNiceSubstring(s.substr(i+1) );

        return left.length()>=right.length() ? left:right;
       } 
       return s;
    }
};