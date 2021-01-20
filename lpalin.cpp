#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int num = s.length();
        string longest;
        int maxLength = 0;
        vector<vector<int>> dp(num, vector<int>(num));
       
        if (s.length() == 0) {
            return longest;
        }
        
        maxLength = 1;
        longest += s[0];
        
        // pre-calc dp 
        for (int i = 0; i < num; i++) {
            dp[i][i] = 1;
            if (i + 1 < num) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 2;
                    maxLength = max(maxLength, 2);
                    longest = s.substr(i, 2);
                }
            }
        }
        
        // calculate from bottom and fill up the table
        for (int i = num - 3; i >= 0; i--) {
            for (int j = i + 2; j < num; j++) {
                //cout << "i , j " << i << ", " << j<< "s[i] = " << s[i] << "s[j] = " << s[j] << endl;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = j - i + 1;
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        
        return longest;
    }
};


int main() 
{
    Solution s;
    assert(s.longestPalindrome("abacab") == "bacab");
    assert(s.longestPalindrome("aba") == "aba");
    assert(s.longestPalindrome("") == "");
    assert(s.longestPalindrome("abakkkkkab") == "bakkkkkab");
    return 0;
}