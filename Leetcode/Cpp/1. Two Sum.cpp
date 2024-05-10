class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map.insert({ nums[i], i });
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end() &&
                map[target - nums[i]] != i) {
                result.push_back(i);
                result.push_back(map[target - nums[i]]);
                return result;
            }
        }
        return result;
    }
};