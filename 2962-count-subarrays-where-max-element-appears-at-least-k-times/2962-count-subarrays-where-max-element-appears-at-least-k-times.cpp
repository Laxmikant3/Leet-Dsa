class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long maxi = *max_element(nums.begin(), nums.end()), count = 0; 

        for (int i = 0 ; i < nums.size() ; i++) {
            long maxOccurrences = 0;
            for (int j = i ; j < nums.size() ; j++) {
                if (nums[j] == maxi) ++maxOccurrences;
                if (maxOccurrences >= k) {
                    ++count;
                }
            }
        } 
        return count;
    }
};