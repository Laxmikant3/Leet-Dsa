class Solution {
public:
        vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(), 0);
        long long t = 0;
        for(int i = 0; i < word.size(); ++i){
            t = (t * 10 + (word[i] - '0') ) % m;
            if(t == 0) ans[i] = 1; 
        }
        return ans;
    }
};