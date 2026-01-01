/*
 * 題目：66. Plus One (加一)
 * 連結：https://leetcode.com/problems/plus-one/
 * 難度：Easy
 * 描述：給定一個由整數組成的非空陣列，表示一個非負整數。將該整數加一。
 * 最高位數字存放在陣列的首位，陣列中每個元素只儲存單個數字。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l = digits.size();
        digits[l - 1] += 1; // 先在最後一位加 1
        
        // 從最後一位往回檢查進位
        for(int i = l - 1; i >= 0; i--)
        {
            // 處理最左邊（最高位）需要進位的情況，例如 99 -> 100
            if(digits[i] == 10 && i == 0)
            {
                digits.insert(digits.begin(), 0);
                digits[i + 1] -= 10;
                digits[i] += 1;
            }
            // 處理一般的進位
            else if(digits[i] == 10)
            {
                digits[i] -= 10;
                digits[i - 1] += 1;
            }
        }
        return digits;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // [1, 2, 3] -> [1, 2, 4]
    // [4, 3, 2, 1] -> [4, 3, 2, 2]
    // [9, 9] -> [1, 0, 0]
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {4, 3, 2, 1},
        {9, 9},
        {0}
    };

    cout << "--- Plus One Test ---" << endl;

    for (auto& digits : testCases) {
        // 印出輸入
        cout << "Input: [";
        for (int i = 0; i < digits.size(); i++) cout << digits[i] << (i == digits.size()-1 ? "" : ",");
        cout << "] -> Output: [";

        // 計算結果
        vector<int> result = sol.plusOne(digits);

        // 印出結果
        for (int i = 0; i < result.size(); i++) cout << result[i] << (i == result.size()-1 ? "" : ",");
        cout << "]" << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}