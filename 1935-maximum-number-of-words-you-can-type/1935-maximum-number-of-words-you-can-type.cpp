class Solution {
public:
    bool fid(string s, string c){
        for( int i=0;i<c.length();i++){
            if(s.find(c[i] )!= string::npos){
                return false;
            }
        }  
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> arr;
        stringstream ss(text);
        string word;
        int count=0;
        while(ss >> word){
            if(fid(word , brokenLetters)){
                count++;
            }
        }
        return count;
    }
};