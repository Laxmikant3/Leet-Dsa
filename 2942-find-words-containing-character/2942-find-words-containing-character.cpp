class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> out;
        for(int i=0;i<words.size();i++){
            string a= words[i];
            for(int j=0;j<a.length();j++){
                if(x==a[j]){
                    out.push_back(i);
                    break;
                }
            }
        }
        return out;
    }
};