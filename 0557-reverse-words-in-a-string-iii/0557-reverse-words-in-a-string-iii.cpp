class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        string result="";
        while (iss >> word) {
            reverse(word.begin(), word.end());
            result+=word;
            result+=" ";
        }
        result.erase(result.size() - 1);
        return result;        
    }
};