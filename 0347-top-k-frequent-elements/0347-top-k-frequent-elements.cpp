class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>mpp;
        for(int it: nums)
        {
            mpp[it]++;
        }
        vector<pair<int,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[] (auto& a ,auto& b) {return a.second > b.second; } );
        for(int i=0;i<k;i++)
        {
            res.push_back(vec[i].first);
        }
        return res;
    }
};