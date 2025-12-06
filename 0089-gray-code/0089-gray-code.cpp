class Solution {
public:


    vector<int> grayCode(int n) {
        vector<int> arr;
        for(int i=0;i<(1<<n);i++){
            arr.push_back(i^(i>>1));
        }
        return arr;
    }
};