class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                seen.insert(nums[j]);
                if (seen.size() == totalDistinct) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
