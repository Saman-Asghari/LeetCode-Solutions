
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int** A = new int* [text1.length() + 1];
        for (int i = 0; i < text1.length() + 1; i++)
            A[i] = new int[text2.length() + 1];

        for (int i = 0; i < text2.length() + 1; i++)
            A[0][i] = 0;
        for (int i = 0; i < text1.length() + 1; i++)
            A[i][0] = 0;

        for (int i = 1; i < text1.length() + 1; i++) {
            for (int j = 1; j < text2.length() + 1; j++) {
                if (text1[i - 1] == text2[j - 1])
                    A[i][j] = 1 + A[i - 1][j - 1];
                else {
                    A[i][j] = A[i][j - 1];
                    if (A[i - 1][j] > A[i][j])
                        A[i][j] = A[i - 1][j];
                }
            }
        }

        return A[text1.length()][text2.length()];
    }
};