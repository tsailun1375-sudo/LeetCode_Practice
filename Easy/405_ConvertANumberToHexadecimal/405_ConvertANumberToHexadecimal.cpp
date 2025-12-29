/*
 * 題目：405. Convert a Number to Hexadecimal (十進位轉十六進位)
 * 連結：https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 * 難度：Easy
 * 描述：將一個整數轉換為十六進位。對於負數，必須以二補數形式表示。
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        // 使用 unsigned int 自動處理負數的二補數表示
        unsigned int u_num = (unsigned int)num; 
        string ans = "";
        
        // 十六進位對照表
        const char hex_map[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

        while (u_num > 0) {
            // u_num & 0xf 等同於 u_num % 16，取最後四位位元
            int remainder = u_num & 0xf; 
            ans.push_back(hex_map[remainder]);
            // u_num >>= 4 等同於 u_num / 16，向右移動四位位元
            u_num >>= 4; 
        }

        // 由於我們是從低位往高位取，最後需要反轉字串
        reverse(ans.begin(), ans.end());         
        return ans;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // 26 -> "1a"
    // -1 -> "ffffffff" (二補數)
    struct TestCase {
        int num;
        string expected;
    };

    vector<TestCase> tests = {
        {26, "1a"},
        {-1, "ffffffff"},
        {0, "0"},
        {16, "10"},
        {-2, "fffffffe"}
    };

    cout << "--- Hexadecimal Conversion Test ---" << endl;

    for (const auto& t : tests) {
        cout << "Input: " << t.num << " -> Hex: " << sol.toHex(t.num) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}