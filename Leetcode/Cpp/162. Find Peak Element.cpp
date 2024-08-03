class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int low = 0, high = nums.size() - 1, mid;
        while (high >= low) {
            mid = (low + high) / 2;
            if (nums[mid] > (mid - 1 >= 0 ? nums[mid - 1] : INT64_MIN) && nums[mid] > (mid + 1 < nums.size() ? nums[mid + 1] : INT64_MIN))
                return mid;
            else {
                if (nums[mid] > (mid - 1 >= 0 ? nums[mid - 1] : INT64_MIN))
                    low = mid + 1;
                else if (nums[mid] < (mid - 1 >= 0 ? nums[mid - 1] : INT64_MAX))
                    high = mid - 1;
            }
        }
        return -1;
    }
};