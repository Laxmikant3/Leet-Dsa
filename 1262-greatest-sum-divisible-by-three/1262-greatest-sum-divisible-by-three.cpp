class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const long long NEG_INF = -1e15;   
        vector<long long> dp(3, NEG_INF);
        dp[0] = 0; 

        for (int x : nums) {
            vector<long long> cur = dp;   
            for (int r = 0; r < 3; r++) {
                if (dp[r] == NEG_INF) continue;  
                int nr = (r + x) % 3;
                cur[nr] = max(cur[nr], dp[r] + x);
            }
            dp = cur;
        }

        return (int)dp[0];   
    }
};
