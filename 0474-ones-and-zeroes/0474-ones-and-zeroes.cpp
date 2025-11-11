class Solution {
public:
    int helper(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if (i == strs.size()) return 0;

        if (dp[i][m][n] != -1) return dp[i][m][n];

        int notPick = helper(strs, m, n, i + 1, dp);

        int zeros = 0, ones = 0;
        for (char c : strs[i]) {
            if (c == '0') zeros++;
            else ones++;
        }

        int pick = 0;
        if (m >= zeros && n >= ones) {
            pick = 1 + helper(strs, m - zeros, n - ones, i + 1, dp);
        }

        return dp[i][m][n] = max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, m, n, 0, dp);
    }
};
