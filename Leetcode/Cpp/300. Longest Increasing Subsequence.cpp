class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int* dp = new int[nums.size()] {0};
        dp[0] = 1;
        int maxIndex = 0;
        bool b = true;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] >= dp[maxIndex]) {
                    maxIndex = j;
                    dp[i] = dp[maxIndex] + 1;
                    b = false;
                }
            }
            if (b)
                dp[i] = 1;
            maxIndex = 0;
            b = true;
        }
        int maxValue = 0;
        for (int i = 0; i < nums.size(); i++)
            if (dp[i] > maxValue)
                maxValue = dp[i];
        return maxValue;
    }
};