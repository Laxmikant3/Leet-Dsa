class Solution {
public:

    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    void cleanSpaces(string &s) {
        int n = s.size(), i = 0, j = 0;
        
        while (j < n && s[j] == ' ') j++; 
        
        while (j < n) { 
            while (j < n && s[j] != ' ')
                s[i++] = s[j++];
            
            while (j < n && s[j] == ' ') j++;
            
            if (j < n)
                s[i++] = ' ';
        }
        
        s.resize(i); 
    }

    string reverseWords(string s) {
        int n = s.size();
        
        reverse(s, 0, n - 1);
        
        int start = 0;
        for (int end = 0; end <= n; end++) {
            if (end == n || s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        
        cleanSpaces(s);
        
        return s;
    }

};