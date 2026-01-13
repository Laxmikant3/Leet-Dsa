class Solution {
public:
    bool isPossible(vector<vector<int>>& pq, double mid){
        double area1 = 0.0, area2 = 0.0;
        for(int i = 0; i < pq.size(); i++){
            if(pq[i][1] + pq[i][2]  <= mid){
                area1 += (double)pow(pq[i][2], 2);
            }else if(pq[i][1] >= mid)
                area2 += (double)pow(pq[i][2], 2);
            else
            {
                area1 += (double)pq[i][2]*(mid - pq[i][1]);
                area2 += (double)pq[i][2]*(pq[i][1] + pq[i][2] - mid);
            }
        }
        return area1 < area2;
    }
    double separateSquares(vector<vector<int>>& squares) {
        
        double l = 0.0;
        double r = 2*1e9;
        while(abs(l-r) >= 0.00001)
        // for(int i = 0; i < 48; i++)
        {
            double mid = (l + r)/2.0;
            if(isPossible(squares, mid)){
                l = mid;
            }else
                r = mid;
        }
        return r;
    }
};