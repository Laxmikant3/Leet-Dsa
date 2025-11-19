class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool brk=true;
        while(brk){
            if(find(nums.begin(), nums.end(), original)==nums.end()){
                brk=false;
                break;
            }
            else{
                original=2*original;
            }
        }
        return original;
    }
};