class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int value = map[s[s.length() - 1]];
        for (int i = s.length() - 1; i > 0; i--) {
            if (map[s[i]] > map[s[i - 1]])
                value -= map[s[i - 1]];
            else value += map[s[i - 1]];
        }
        return value;
    }
};
