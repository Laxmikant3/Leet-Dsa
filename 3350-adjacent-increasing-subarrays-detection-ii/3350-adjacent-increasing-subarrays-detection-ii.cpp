
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int maxK = 0, prev = 0, curr = 1;        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
            } else {
                maxK = max({maxK, curr / 2, min(prev, curr)});
                prev = curr;
                curr = 1;
            }
        }        
        maxK = max({maxK, curr / 2, min(prev, curr)});        
        return maxK;
    }
};