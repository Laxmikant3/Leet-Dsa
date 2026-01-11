class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n =matrix.size() ; 
        int m= matrix[0].size() ; 
        int ans =0 ; 
        for(int i= 0 ; i<n ; i++){
            vector<int>compress(m,0) ; 
            for(int j= i ; j<n ; j++){
                int c= 0 ;
                for(int k= 0; k<m ; k++){
                    compress[k]+=matrix[j][k]-'0' ;
                    if(compress[k]==j-i+1)c++ ; 
                    else c=0  ;
                    ans=max(ans , c*(j-i+1)) ;  
                }
            }
        }
        return ans ;
    }
};