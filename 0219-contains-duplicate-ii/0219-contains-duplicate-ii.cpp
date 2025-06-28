class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!k) return 0;
        unordered_map<int,int> freq;
        int num = INT_MIN;
        int i=0;
        for(i=0;i<nums.size() && i<=k;i++){
        freq[nums[i]]++;
        if(freq[nums[i]] >= 2) num = nums[i];
        if(num != INT_MIN) return 1;
        }
        for(i;i<nums.size();i++){
            freq[nums[i-k-1]]--;
            freq[nums[i]]++;
            if(freq[nums[i]] >= 2) return 1;
        }

        return 0;
    }
};