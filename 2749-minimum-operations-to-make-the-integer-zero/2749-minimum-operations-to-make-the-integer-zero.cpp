class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long i = 0;i<=60;i++){ //loop till 60 usign long long 
            long long val =1LL*num1 - (i*num2); // taking out the value
            if(val<0) continue; //value becomes negative move to next possible ans
            if(__builtin_popcountll(val)<=i && i<=val) return i; // returns only if the min bits are lesser then the value
        }
        return -1;
    }
};