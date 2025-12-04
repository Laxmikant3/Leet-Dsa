class Solution {
public:
    int countCollisions(string d) {
        int n= d.size();
        if(n==0) return 0;
        int l=0, r=n-1;
        while(d[l]=='L'){
            l++;
        }
        while(l<r && d[r]=='R') r--;
        if(l>=r)return 0;
        int col=0;
        for( ;l<=r;l++){
            col+=d[l]!='S';
        }
        return col;
    }
};