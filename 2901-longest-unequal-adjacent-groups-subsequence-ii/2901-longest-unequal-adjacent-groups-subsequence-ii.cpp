class Solution {
public:
        int hammingDistance(const string& s1, const string& s2) {
            int count = 0;
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] != s2[i]) count++;
            }
            return count;
        }

        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n = words.size();
            vector<int> dp(n, 1);
            vector<int> prevIndex(n, -1); 
            int maxIdx = 0, maxLen = 1;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (groups[i] != groups[j] && words[i].size() == words[j].size() && hammingDistance(words[i], words[j]) == 1) {
                        if (dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            prevIndex[i] = j;
                        }
                    }
                }
                if (dp[i] > maxLen) {
                    maxLen = dp[i];
                    maxIdx = i;
                }
            }
            vector<string> result;
            while (maxIdx != -1) {
                result.insert(result.begin(), words[maxIdx]);
                maxIdx = prevIndex[maxIdx];
            }

            return result;
    }
};