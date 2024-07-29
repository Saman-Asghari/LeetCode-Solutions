#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;
        if (target > nums[high - 1]) {
            return high;
        }
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (target < nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }
        return  low;
    }
};
int main() {
    vector<int> vec = { 1,3,5,6 };
    Solution s1;
    cout << s1.searchInsert(vec,2);
}
