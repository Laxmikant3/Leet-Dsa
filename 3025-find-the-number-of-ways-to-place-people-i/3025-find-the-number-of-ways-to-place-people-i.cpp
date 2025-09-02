class Solution {
public:
static bool comp(vector<int> &a , vector<int> &b){
    if (a[0] == b[0]) return a[1] > b[1]; 
        return a[0] < b[0];
}
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int n = points.size(),ans=0;
        map<int,int> m;
        for(int i =0;i<n;i++){
            int y = INT_MAX;
            for(int j =i-1;j>=0;j--){
            if(points[i][0]>=points[j][0] && points[i][1]<=points[j][1]){
                if(points[j][1]<y){ans++;y=points[j][1];}
            }
            }
        }
        return ans;
    }
};