/*
 * 題目：258. Add Digits (各位相加)
 * 連結：https://leetcode.com/problems/add-digits/
 * 難度：Easy
 * 描述：給定一個非負整數 num，反覆將各個位數相加，直到結果為一位數為止。
 * 例如：38 -> 3 + 8 = 11 -> 1 + 1 = 2。回傳 2。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int addDigits(int num) {  
        // 當 num 還是兩位數以上時持續執行
        while(num > 9)
        {
            int sum = 0, temp = num;
            // 內層迴圈：計算當前數字的所有位數總和
            while(temp > 9)
            {
                sum += temp % 10;
                temp /= 10;
            }
            sum += temp; // 加上最後剩下的最高位數
            num = sum;   // 更新 num 進入下一次判斷
        }
        return num;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // 38 -> 2
    // 0 -> 0
    // 9 -> 9
    // 123 -> 1+2+3 = 6
    vector<int> testCases = {38, 0, 9, 123, 999};

    cout << "--- Add Digits Test ---" << endl;
    for (int n : testCases) {
        cout << "Input: " << n << " -> Result: " << sol.addDigits(n) << endl;
    }

    return 0;
}