class Solution {
public:
    int countTriples(int n) {
        
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int c= i*i+j*j;
                int c2=sqrt(c);
                if(c2<=n && c2*c2==c){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};