class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n; i++) {
            int left = i;
            int right = n - i;
            if (!containsZero(left) && !containsZero(right)) {
                return {left, right};
            }
        }
        return {-1, -1};
    }

    bool containsZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    }
};