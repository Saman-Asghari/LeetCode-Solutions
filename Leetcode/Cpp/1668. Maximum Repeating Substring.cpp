class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.length() < word.length())
            return 0;
        int* dp = new int[sequence.length()];
        int max;
        if (sequence.substr(0, word.length()) == word) {
            for (int i = 0; i < word.length() - 1; i++)
                dp[i] = 0;
            dp[word.length() - 1] = 1;
            max = 1;
        }
        else {
            for (int i = 0; i < word.length(); i++)
                dp[i] = 0;
            max = 0;
        }
        for (int i = word.length(); i < sequence.length(); i++) {
            if (sequence.substr(i - word.length() + 1, word.length()) == word) {
                dp[i] = dp[i - word.length()] + 1;
            }
            else dp[i] = 0;
            if (dp[i] > max)
                max = dp[i];
        }
        if (dp[sequence.length() - 1] > max)
            max = dp[word.length() - 1];
        return max;
    }
};