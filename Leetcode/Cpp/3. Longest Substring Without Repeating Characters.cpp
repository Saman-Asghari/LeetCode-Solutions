class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int>map;
        int max = 0, counter = 0;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                counter++;
                map[s[i]] = i;
            }
            else {
                if (counter > max)
                    max = counter;
                counter = 0;
                i = map[s[i]];
                map.clear();

            }
        }
        if (counter > max)
            max = counter;
        return max;
    }
};
