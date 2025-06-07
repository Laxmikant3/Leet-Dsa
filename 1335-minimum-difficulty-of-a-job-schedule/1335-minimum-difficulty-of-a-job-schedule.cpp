class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jd,int n,int i, int d){
        if(d == 1){
            int maxD=jd[i];
            for(int j=i;j<n;j++){
                maxD=max(maxD , jd[j]);
                
            }
            return maxD;
        }

        if(t[i][d]!=-1){
            return t[i][d];
        }
        int maxD = jd[i];
        int final_result = INT_MAX;
        for(int j=i;j<=n-d;j++){
            maxD=max(maxD , jd[j]);

            int result = maxD+solve(jd,n,j+1,d-1);
            final_result = min(final_result , result);
        }
        return t[i][d]=final_result;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n= jd.size();
        if(n<d){
            return -1;
        }
        memset(t,-1,sizeof(t));
        return solve(jd,n,0,d);
    }
};