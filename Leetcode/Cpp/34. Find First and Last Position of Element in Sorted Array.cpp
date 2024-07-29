class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);

        vector<int>res;
        res.push_back(-1);
        res.push_back(-1);
        if (nums.size() == 0) {
            return res;
        }
        if (nums.size() == 1) {
            if (nums[0] == target) {
                res[0] = res[1] = 0;
            }
            return res;
        }

        // find first position
        int low = 0, high = nums.size() - 1, mid;
        while (high >= low) {

            mid = (low + high) / 2;
            if (nums[mid] == target) {
                res[0] = mid;
                high = mid - 1;
            }
            else {
                if (target < nums[mid])
                    high = mid - 1;
                else if (target > nums[mid])
                    low = mid + 1;
            }
        }

        //find last position
        low = 0, high = nums.size() - 1;
        while (high >= low) {

            mid = (low + high) / 2;
            if (nums[mid] == target) {
                res[1] = mid;
                low = mid + 1;
            }
            else {
                if (target < nums[mid])
                    high = mid - 1;
                else if (target > nums[mid])
                    low = mid + 1;
            }
        }
        return res;
    }
};