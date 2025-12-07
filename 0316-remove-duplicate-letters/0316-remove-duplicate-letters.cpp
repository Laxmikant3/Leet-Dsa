class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        unordered_set<char> seen;
        unordered_map<char , int> last_occ;
        for(int i=0;i<s.length();i++){
            last_occ[s[i]]=i;

        }
        for(int i=0;i<s.length();i++){
            char c= s[i];
            if(seen.find(c)==seen.end()){
                while(!stk.empty() && c<stk.top() && i<last_occ[stk.top()]){
                    seen.erase(stk.top());
                    stk.pop();
                }
                seen.insert(c);
                stk.push(c);
            }
        }

        string res="";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};