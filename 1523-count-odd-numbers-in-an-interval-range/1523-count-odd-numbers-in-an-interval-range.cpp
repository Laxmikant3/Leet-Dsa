class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        for(;low<=high;low++){
            if(low%2!=0){
                count++;
            }
        }
        return count;
    }
};