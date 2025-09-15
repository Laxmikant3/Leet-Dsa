class Solution {
public:
    int backtrac(int start , string& s,unordered_set<string>& seen){

        if( start == s.size()){
            return 0;
        }
        int maxsplit=0;
        for( int i=start+1; i<=s.size();i++){
            string subs= s.substr(start , i-start);
            if(seen.find(subs) == seen.end()){
                seen.insert(subs);
                maxsplit = max(maxsplit , 1+ backtrac(i,s,seen));
                seen.erase(subs);
            }
        }
        return maxsplit;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string > seen;
        return backtrac(0,s,seen);
    }
};