class Solution {
public:
    int maxDifference(string s) {
         sort(begin(s), end(s));

        int mx_odd = 0, min_ev = INT_MAX;

        char cur = s[0]; 
        int cnt = 1;    

        for(int i=1;i<s.size();i++){
            if(cur == s[i]){cnt++;}
            else{
                if(cnt&1){mx_odd = max(mx_odd, cnt);}
                else{min_ev = min(min_ev, cnt);}

                cur = s[i];
                cnt = 1;
            }
        }

        if(cnt&1){mx_odd = max(mx_odd, cnt);}
        else{min_ev = min(min_ev, cnt);}

        return mx_odd - min_ev;
    }
};