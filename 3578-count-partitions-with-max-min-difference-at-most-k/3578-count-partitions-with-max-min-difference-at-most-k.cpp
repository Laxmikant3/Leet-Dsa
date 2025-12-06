class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {

        const int MOD = 1e9+7;
        int n=nums.size();
        vector<long long> dp(n+1), prefix(n+2);
        dp[0]=1;
        prefix[1]=1;
        deque<int> max,min;
        int l=0;
        for(int i=0;i<n;++i){
            while(!max.empty() && nums[max.back()]<=nums[i]){
                max.pop_back();

            }
            while(!min.empty() && nums[min.back()]>=nums[i]){
                min.pop_back();
            }

            max.push_back(i);
            min.push_back(i);

            while(nums[max.front()]-nums[min.front()]>k){
                if(max.front()==l){
                    max.pop_front();

                }
                if(min.front()==l){
                min.pop_front();
                }
                ++l;
            }

            dp[i+1] = (prefix[i+1]-prefix[l]+MOD)%MOD;
            prefix[i+2]=(prefix[i+1]+dp[i+1])%MOD;
        }
        return dp[n];
    }
};