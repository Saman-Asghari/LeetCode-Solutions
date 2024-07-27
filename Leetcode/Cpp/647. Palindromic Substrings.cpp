class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0, l = s.length();
        bool** dp = new bool* [l];
        for (int i = 0; i < l; i++)
            dp[i] = new bool[l] {false};
        for (int diagonal = 0; diagonal < l; diagonal++) {
            for (int i = 0; i < l - diagonal; i++) {
                if (diagonal == 0) {
                    dp[i][i + diagonal] = true;
                    counter++;
                }
                else
                    if (s[i] == s[i + diagonal]) {
                        if (i + 1 <= i + diagonal - 1) {
                            if (dp[i + 1][i + diagonal - 1] == true) {
                                dp[i][i + diagonal] = true;
                                counter++;
                            }
                            else dp[i][i + diagonal] = false;;
                        }
                        else {
                            dp[i][i + diagonal] = true;
                            counter++;
                        }
                    }
                    else dp[i][i + diagonal] = false;
            }
        }
        return counter;
    }
};