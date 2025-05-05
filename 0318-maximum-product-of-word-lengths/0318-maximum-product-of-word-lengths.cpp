class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), maxProd = 0;
        vector<int> bitmasks(n, 0), lengths(n, 0);
         
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                bitmasks[i] |= (1 << (c - 'a')); 
            }
            lengths[i] = words[i].size();  
        }
        
         for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((bitmasks[i] & bitmasks[j]) == 0) {  
                    maxProd = max(maxProd, lengths[i] * lengths[j]);
                }
            }
        }
        
        return maxProd;
    }
};
