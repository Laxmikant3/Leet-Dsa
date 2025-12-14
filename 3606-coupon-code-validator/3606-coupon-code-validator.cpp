class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& line, vector<bool>& active) {
        int n = code.size();
        unordered_map<string, int> line_id;
        line_id["electronics"] = 1;
        line_id["grocery"]     = 2;
        line_id["pharmacy"]    = 3;
        line_id["restaurant"]  = 4;

        auto good_char = [](char c) -> bool{
            return ('a' <= c && c <= 'z') 
                 ||('A' <= c && c <= 'Z')
                 ||('0' <= c && c <= '9')
                 ||(c == '_');
        };
        vector<int> valid;
        for(int i = 0; i < n; i ++){
            if(!line_id[line[i]] || code[i].empty()){
                active[i] = false;
            }
            if(active[i]){
                for(auto c : code[i]){
                    if(!good_char(c)){
                        active[i] = false;
                        break;
                    }
                }
            }
            if(active[i]){
                valid.push_back(i);
            }
        }
        
        sort(valid.begin(), valid.end(), [&](const int &i, const int &j){
            if(line_id[line[i]] != line_id[line[j]]){
                return line_id[line[i]] < line_id[line[j]];
            }
            return code[i] < code[j];
        });

        vector<string> ans;
        for(auto i : valid) ans.push_back(code[i]);
        return ans;
    }
};