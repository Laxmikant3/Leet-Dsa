class Solution {
public:
    const int MOD = 1e9 + 7;

    void generateRows(int m, int row, int mask, vector<int>& validMasks) {
        if (row == m) {
            validMasks.push_back(mask);
            return;
        }
        for (int color = 1; color <= 3; color++) {
            if (row == 0 || (mask % 10) != color) {
                generateRows(m, row + 1, mask * 10 + color, validMasks);
            }
        }
    }

    int colorTheGrid(int m, int n) {
        vector<int> validMasks;
        generateRows(m, 0, 0, validMasks);

        unordered_map<int, vector<int>> transitions;
        for (int mask1 : validMasks) {
            for (int mask2 : validMasks) {
                bool valid = true;
                int temp1 = mask1, temp2 = mask2;
                for (int i = 0; i < m; i++) {
                    if (temp1 % 10 == temp2 % 10) {
                        valid = false;
                        break;
                    }
                    temp1 /= 10;
                    temp2 /= 10;
                }
                if (valid) transitions[mask1].push_back(mask2);
            }
        }

        unordered_map<int, int> dp;
        for (int mask : validMasks) dp[mask] = 1;

        for (int col = 1; col < n; col++) {
            unordered_map<int, int> newDp;
            for (auto& [mask, count] : dp) {
                for (int nextMask : transitions[mask]) {
                    newDp[nextMask] = (newDp[nextMask] + count) % MOD;
                }
            }
            dp = newDp;
        }

        int result = 0;
        for (auto& [mask, count] : dp) result = (result + count) % MOD;

        return result;
    }
};