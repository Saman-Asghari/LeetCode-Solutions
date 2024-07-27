class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int>lvec(&nums[0], &nums[floor(nums.size() / 2)]), rvec(&nums[floor(nums.size() / 2)], &nums[nums.size()]);
        int rightMax = maxSubArray(rvec);
        int leftMax = maxSubArray(lvec);
        int middleMax = numeric_limits<int>::min(), sum = 0;
        for (int i = floor(nums.size() / 2) - 1; i >= 0; i--) {
            sum += nums[i];
            if (sum > middleMax)
                middleMax = sum;
        }
        sum = 0;
        int prev = middleMax;
        for (int i = floor(nums.size() / 2); i < nums.size(); i++) {
            sum += nums[i];
            if (sum + prev > middleMax)
                middleMax = sum + prev;
        }
        int max = leftMax;
        if (rightMax > max)
            max = rightMax;
        if (middleMax > max)
            max = middleMax;
        return max;
    }
};