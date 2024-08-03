class Solution {
public:
    int longestValidParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        stack<int>stck;
        int l = s.length(), max = 0;
        int* dp = new int[l];
        for (int i = 0; i < l; i++) {
            if (s[i] == '(') {
                dp[i] = 0;
                stck.push(i);
            }
            else {
                if (!stck.empty()) {
                    dp[i] = i - stck.top() + 1 + (stck.top() - 1 >= 0 ? dp[stck.top() - 1] : 0);
                    if (dp[i] > max)
                        max = dp[i];
                    stck.pop();
                }
                else dp[i] = 0;
            }
        }
        return max;
    }
};