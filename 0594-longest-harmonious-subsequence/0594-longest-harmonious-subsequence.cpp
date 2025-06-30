class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxa = 0;
        for(int i:nums){
            m[i]++;
        }
        for(int i:nums){
            if(m[i-1] || m[i+1]){
                maxa = max({maxa, m[i] + m[i-1], m[i] + m[i+1]});
            }
        }
        return maxa;
    }
};