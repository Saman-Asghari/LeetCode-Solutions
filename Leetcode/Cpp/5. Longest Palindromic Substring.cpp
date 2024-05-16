#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int l = s.length(), minIndex = 0, maxIndex = 0, maxLength = 1;
        bool** dp = new bool* [l];
        for (int i = 0; i < l; i++)
            dp[i] = new bool[l] {false};
        for (int diagonal = 0; diagonal < l; diagonal++) {
            for (int i = 0; i < l - diagonal; i++) {
                if (diagonal == 0) {
                    dp[i][i + diagonal] = true;
                }
                else
                    if (s[i] == s[i + diagonal]) {
                        if (i + 1 <= i + diagonal - 1) {
                            if (dp[i + 1][i + diagonal - 1] == true) {
                                dp[i][i + diagonal] = true;
                                if (diagonal + 1 > maxLength) {
                                    minIndex = i;
                                    maxIndex = i + diagonal;
                                }
                            }
                            else dp[i][i + diagonal] = false;;
                        }
                        else {
                            dp[i][i + diagonal] = true;
                            if (diagonal + 1 > maxLength) {
                                minIndex = i;
                                maxIndex = i + diagonal;
                            }
                        }
                    }
                    else dp[i][i + diagonal] = false;
            }
        }
        return s.substr(minIndex, maxIndex - minIndex + 1);
    }
};