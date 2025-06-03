class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bitset<200002> bf;
        int sumA = 0, sumB = 0;
        for (auto n : A) sumA += n;
        for (auto n : B) {
            sumB += n;
            bf.set(2 * n);
        }
        int diff = sumA - sumB;
        for (auto n : A) {
            int det = 2 * n - diff;
            if (det > 0 && det < 200002 && bf.test(det)) return {n, (2 * n - diff) / 2};
        }
        return {};
    }
};