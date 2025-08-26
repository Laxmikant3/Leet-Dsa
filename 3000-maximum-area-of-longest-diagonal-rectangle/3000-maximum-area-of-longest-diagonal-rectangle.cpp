class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    float max1=0;
    int out=0;
 
    for(int i=0;i<dimensions.size();i++){
       float area=0;
        vector<int> a=dimensions[i];
        area=sqrt(a[0]*a[0] + a[1]*a[1]);
        if(area>max1){
            max1=area;
            out=a[0]*a[1];
        }
        else if(area == max1){
            out=max(out,a[0]*a[1]);
        }
    }
    return out;
    }
};