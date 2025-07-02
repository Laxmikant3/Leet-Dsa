class Solution {
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(const string& word, int k) {
        vector<pair<char, int>> charCounts;
        int n = word.length();
        
        // Count consecutive characters
        for (int i = 0; i < n; ) {
            char currentChar = word[i];
            int count = 0;
            while (i < n && word[i] == currentChar) {
                count++;
                i++;
            }
            charCounts.push_back({currentChar, count});
        }
        
        int m = charCounts.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; 

        // Dynamic programming to count possible strings
        for (auto& [ch, freq] : charCounts) {
            vector<long long> newDp(n + 1, 0);
            vector<long long> prefixSum(n + 2, 0);
            
            for (int i = 0; i <= n; i++) {
                prefixSum[i + 1] = (prefixSum[i] + dp[i]) % MOD;
            }
            
            for (int i = 0; i <= n; i++) {
                if (i + 1 <= n) {
                    newDp[i + 1] = (newDp[i + 1] + dp[i]) % MOD;
                }
                if (i + freq + 1 <= n) {
                    newDp[i + freq + 1] = (newDp[i + freq + 1] - dp[i] + MOD) % MOD;
                }
            }
            
            for (int i = 1; i <= n; i++) {
                newDp[i] = (newDp[i] + newDp[i - 1]) % MOD;
            }
            
            dp = newDp; 
        }
        
        long long totalCount = 0;
        for (int length = k; length <= n; length++) {
            totalCount = (totalCount + dp[length]) % MOD;
        }

        return totalCount;
    }
};