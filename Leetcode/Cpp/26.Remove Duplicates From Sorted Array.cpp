#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        list<int> ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }
        for(int number:ans)
        {
            cout << number << " ";
        }
        return ans.size();
    }
};
int main() {
    vector<int> vec = { 0,0,1,1,1,2,2,3,3,4 };
    Solution s1;
    cout << s1.removeDuplicates(vec);
}
