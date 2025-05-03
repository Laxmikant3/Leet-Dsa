class Solution {
public:
    int countRotations(int target, vector<int>& tops, vector<int>& bottoms) {
        int topRotations = 0, bottomRotations = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) 
                return INT_MAX; 
            else if (tops[i] != target) 
                ++topRotations;
            else if (bottoms[i] != target) 
                ++bottomRotations;
        }
        return min(topRotations, bottomRotations);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int candidate1 = tops[0], candidate2 = bottoms[0];
        int rotations = min(countRotations(candidate1, tops, bottoms), 
                            countRotations(candidate2, tops, bottoms));
        
        return (rotations == INT_MAX) ? -1 : rotations;
    }
};