class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long count = 0;
        int left = 0;
        long long currentSum = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];
            
            while (currentSum * (right - left + 1) >= k) {
                currentSum -= nums[left];
                ++left;
            }
            
            count += (right - left + 1);
        }

        return count;
    }
};