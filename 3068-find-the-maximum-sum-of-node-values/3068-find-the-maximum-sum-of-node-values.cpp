class Solution 
{
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        // Step 1: Compute base sum
        long long baseSum = 0;
        vector<int> gains;

        // Step 2: Calculate gain for each number
        for (int num : nums) 
        {
            int xorVal = num ^ k;
            int gain = xorVal - num;
            baseSum += num;
            gains.push_back(gain);
        }

        // Step 3: Sort gains descending
        sort(gains.rbegin(), gains.rend());

        // Step 4: Track maximum even-counted gain
        long long maxGain = 0, currentGain = 0;
        int count = 0;

        for (int g : gains) 
        {
            currentGain += g;
            count++;
        
            // Step 5: Only use even number of XORs
            if (count % 2 == 0) 
            {
                maxGain = max(maxGain, currentGain);
            }
        }

        // Step 6: Add best gain to base
        return baseSum + maxGain;
    }
};