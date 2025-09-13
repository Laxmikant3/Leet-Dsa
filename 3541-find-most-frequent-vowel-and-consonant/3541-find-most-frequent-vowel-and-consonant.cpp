class Solution {
public:
    int maxFreqSum(string s) {

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> freq(26, 0);

        int maxVowel = 0, maxConsonant = 0;

        for (char c : s) {
            int idx = c - 'a';
            freq[idx]++;

            if (vowels.count(c)) {
                maxVowel = max(maxVowel, freq[idx]);
            } else {
                maxConsonant = max(maxConsonant, freq[idx]);
            }
        }

        return maxVowel + maxConsonant;
    }
};