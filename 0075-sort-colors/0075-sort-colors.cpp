class Solution {
public:
    void sortColors(vector<int>& nums) {
        int temp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
            if(nums[i]<nums[j]){
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }}
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
        }
        
    }
};