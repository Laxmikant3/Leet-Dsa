class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s= to_string(n);
        int flag=s.length();
        for(int i=s.length()-1;i>0;i--){
            if(s[i]<s[i-1]){
                flag=i;

                s[i-1]=s[i-1]-1;
            }
        }
        for(int i=flag;i<s.length();i++){
            s[i]='9';
        }
        return stoi(s);
    }
};