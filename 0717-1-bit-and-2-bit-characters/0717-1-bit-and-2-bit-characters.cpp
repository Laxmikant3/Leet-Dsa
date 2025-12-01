class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
         int i=0;
        for( i=0; i<bits.size()-1; i++){
            i+=(bits[i]==1);
        }
        return i==bits.size()-1;
    }
};