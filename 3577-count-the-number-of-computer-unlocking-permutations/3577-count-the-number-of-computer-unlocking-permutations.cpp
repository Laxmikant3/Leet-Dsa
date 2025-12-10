class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int MOD = 1e9+7;
        int n=complexity.size();
        int first=complexity[0];
        for(int i=1;i<n;i++){
            if(complexity[i]<=first) return 0;
        }
        long long fact=1;
        for(int i=2;i<n;i++){
            fact=( fact*i)%MOD;

        }
        return (int)fact;
    }
};