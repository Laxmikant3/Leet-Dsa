class Solution {
public:
    long long minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL) % p;
    
        if (totalSum == 0) {
            return 0;  
        }
        
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1;
        
        long long currentMod = 0;
        int  minLength = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            currentMod = (currentMod + nums[i]) % p;
            
            long long targetMod = (currentMod - totalSum + p) % p;
            
            if (prefixModMap.find(targetMod) != prefixModMap.end()) {
                minLength = min(minLength, i - prefixModMap[targetMod]);
            }
            
            prefixModMap[currentMod] = i;
        }
        
        return minLength == nums.size() ? -1 : minLength; 
    }
};