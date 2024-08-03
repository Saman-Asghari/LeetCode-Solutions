class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end())
                map.insert({ nums[i],1 });
            else
                map[nums[i]]++;
            if (map[nums[i]] > nums.size() / 2)
                return nums[i];

        }
        return -1;
    }
};