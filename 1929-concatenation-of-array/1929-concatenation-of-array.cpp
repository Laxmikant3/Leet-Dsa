class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int c=nums.size();
        for(int i=0;i<c;i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};