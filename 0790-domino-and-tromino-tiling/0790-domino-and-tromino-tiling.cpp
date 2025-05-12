class Solution {
public:
    
    const int MOD = 1e9 + 7;
    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1; 
        dp[1] = 1; 
        dp[2] = 2; 

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * dp[i - 3]) % MOD;
            for (int j = 0; j < i - 3; j++) {
                dp[i] = (dp[i] + 2 * dp[j]) % MOD;
            }
        }

        return dp[n];
    }
};