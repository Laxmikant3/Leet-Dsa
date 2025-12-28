class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto o : operations) x += (44 - o.at(1));
        return x;
    }
};