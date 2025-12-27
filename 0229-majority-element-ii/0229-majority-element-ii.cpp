class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<int> out;

        int m=nums.size()/3;
        for(auto
         num:map){
            if(num.second>m){
                out.push_back(num.first);
            }
        }
        return out;
    }
};