class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int> > mp;
        int n= mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        bool flag=true;
        for(auto i:mp){
            if(flag){
                reverse(i.second.begin(),i.second.end());

            }
            flag = !flag;
            for(int num:i.second){
                ans.push_back(num);
            }
        }
        return ans;
    }
};