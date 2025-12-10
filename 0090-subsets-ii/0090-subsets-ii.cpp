class Solution {
public:
    void backtrack(vector<int>& nums, int i,vector<vector<int>>& ans,vector<int>& arr){
        if(i==nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        backtrack(nums,i+1,ans,arr);
        arr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        backtrack(nums,i+1,ans,arr);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,ans,arr);
        
        return ans;

    }
};