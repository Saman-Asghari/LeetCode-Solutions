class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        unordered_map<int, char>map;
        map[1] = 'I';
        map[5] = 'V';
        map[10] = 'X';
        map[50] = 'L';
        map[100] = 'C';
        map[500] = 'D';
        map[1000] = 'M';
        int numberOfDigits = 0, temp = num, currentDigit;
        while (temp > 0) {
            temp /= 10;
            numberOfDigits++;
        }
        for (int i = numberOfDigits - 1; i >= 0; i--) {
            currentDigit = num / (int)pow(10, i);
            num %= (int)pow(10, i);
            if (currentDigit != 4 && currentDigit != 9) {
                int value = currentDigit * pow(10, i), romanValue;
                char romanDigit;
            line1:        if (value >= 1000) {
                romanDigit = map[1000];
                romanValue = 1000;
            }
            else if (value >= 500) {
                romanDigit = map[500];
                romanValue = 500;
            }
            else if (value >= 100) {
                romanDigit = map[100];
                romanValue = 100;
            }
            else if (value >= 50) {
                romanDigit = map[50];
                romanValue = 50;
            }
            else if (value >= 10) {
                romanDigit = map[10];
                romanValue = 10;
            }
            else if (value >= 5) {
                romanDigit = map[5];
                romanValue = 5;
            }
            else if (value >= 1) {
                romanDigit = map[1];
                romanValue = 1;
            }
            while (value >= romanValue) {
                result += romanDigit;
                value -= romanValue;
            }
            if (value > 0)
                goto line1;
            }
            else if (currentDigit == 4) {
                int value = currentDigit * pow(10, i);
                //char romanDigit;
                if (value == 4)
                    result += "IV";
                else if (value == 40)
                    result += "XL";
                else if (value == 400)
                    result += "CD";
            }
            else {
                int value = currentDigit * pow(10, i);
                //char romanDigit;
                if (value == 9)
                    result += "IX";
                else if (value == 90)
                    result += "XC";
                else if (value == 900)
                    result += "CM";
            }
        }
        return result;
    }
};