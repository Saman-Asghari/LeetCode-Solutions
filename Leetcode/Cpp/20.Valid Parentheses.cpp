#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> Phrase;
        for (int i = 0; i < s.length(); i++) 
            
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                Phrase.push(s[i]);
            }
            else {
                if (Phrase.empty()) {
                    return false;
                }
                else {
                    char temp = Phrase.top();

                    if (s[i] == ']' && temp != '[') {
                        return false;
                    }
                    if (s[i] == '}' && temp != '{') {
                        return false;
                    }
                    if (s[i] == ')' && temp != '(') {
                        return false;
                    }
                    Phrase.pop();
                }
                
            }
        
        if (!Phrase.empty()) {
            return false;
        }
        return true;
    }
};
int main() {
    Solution s1;
    cout << s1.isValid("]");
}
