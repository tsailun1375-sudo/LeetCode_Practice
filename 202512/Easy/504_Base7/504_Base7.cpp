/*
 * 題目：504. Base 7 (七進位制)
 * 連結：https://leetcode.com/problems/base-7/
 * 難度：Easy
 * 描述：給你一個整數 num，請你將其轉換為七進位制，並以字串形式輸出。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        // 處理 0 的特殊情況
        if (num == 0) return "0";

        int sum = 0, i = 1;
        bool pos = true;

        if (num < 0) {
            num = -num;
            pos = false;
        }

        while (num >= 7) {
            sum += (num % 7) * i;
            num = num / 7;
            i *= 10;
        }
        sum += num * i;

        if (!pos) {
            sum = -sum;
        }

        return to_string(sum);
    }
};

int main() {
    Solution sol;

    // 準備測試範例
    // 100 -> "202" (100 = 2*49 + 0*7 + 2)
    // -7  -> "-10"
    vector<int> testCases = {100, -7, 0, 7, 10, -100};

    cout << "--- Base 7 Conversion Test ---" << endl;

    for (int num : testCases) {
        cout << "Input: " << num << " -> Output: " << sol.convertToBase7(num) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}