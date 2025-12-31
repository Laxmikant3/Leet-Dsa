class Solution {
public:
  int ro[4]={-1,1,0,0};
  int co[4]={0,0,-1,1};
bool helper(int mid,vector<vector<int>>& cells,int row,int col){
   // vector<vector<int>>vis(row,vector<int>(col,0));
    vector<vector<int>>grid(row,vector<int>(col,0));
    for(int i=0;i<=mid;i++){
        grid[cells[i][0]-1][cells[i][1]-1]=1;
    }
    queue<pair<int,int>>q;
    for(int i=0;i<col;i++){
        if(grid[0][i]==0){
            q.push({0,i});
           // vis[0][i]=1;
        }
    }
    while(!q.empty()){
      int r=q.front().first;
      int c=q.front().second;
      if(r==row-1)return true;
      q.pop();   
      for(int i=0;i<4;i++){
        int nr=r+ro[i];
        int nc=c+co[i];
        if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc]==0){
            q.push({nr,nc});
            grid[nr][nc]=1;
        }

      }

    }
    return false;

}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        int low=0,high=n-1;
         int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(mid,cells,row,col)){
                  ans=mid;
                  low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans+1;
    }
};