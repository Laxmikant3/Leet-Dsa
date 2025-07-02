class Solution {
public:
    int possibleStringCount(string word) {
            int count = 1; 
    int n = word.length();

    for (int i = 0; i < n; ) {
        char currentChar = word[i];
        int j = i;
        

        while (j < n && word[j] == currentChar) {
            j++;
        }

        int consecutiveCount = j - i; 
        
        
        if (consecutiveCount > 1) {
            count += consecutiveCount - 1; 
        }

        i = j; 
    }

    return count;
    
    }

};