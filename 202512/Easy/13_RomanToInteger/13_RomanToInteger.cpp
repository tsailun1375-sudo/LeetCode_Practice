/*
 * 題目：13. Roman to Integer
 * 連結：https://leetcode.com/problems/roman-to-integer/
 * 難度：Easy
 * 描述：將給定的羅馬數字字串轉換為對應的整數。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int total = 0;
        int tem1 = 0, tem2 = 0;

        for (int i = 0; i < n; i++) {
            // 處理當前字元 a
            char a = s[i];
            if (a == 'I') tem1 = 1;      
            else if (a == 'V') tem1 = 5; 
            else if (a == 'X') tem1 = 10; 
            else if (a == 'L') tem1 = 50; 
            else if (a == 'C') tem1 = 100; 
            else if (a == 'D') tem1 = 500; 
            else if (a == 'M') tem1 = 1000; 

            // 處理下一個字元 b，確保不越界
            if (i + 1 < n) {
                char b = s[i+1];
                if (b == 'I') tem2 = 1;
                else if (b == 'V') tem2 = 5;
                else if (b == 'X') tem2 = 10;
                else if (b == 'L') tem2 = 50;
                else if (b == 'C') tem2 = 100;
                else if (b == 'D') tem2 = 500;
                else if (b == 'M') tem2 = 1000;
            } else {
                tem2 = 0;
            }

            // 羅馬數字核心邏輯
            if (tem1 < tem2) {
                total -= tem1;
            } else {
                total += tem1;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    
    // 測試範例
    vector<string> testCases = {"III", "LVIII", "MCMXCIV"};
    
    for (const string& test : testCases) {
        cout << "Input: " << test << " -> Output: " << sol.romanToInt(test) << endl;
    }

    return 0;
}