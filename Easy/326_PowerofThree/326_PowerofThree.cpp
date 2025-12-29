/*
 * 題目：326. Power of Three (3 的冪次方)
 * 連結：https://leetcode.com/problems/power-of-three/
 * 難度：Easy
 * 描述：給定一個整數 n，判斷其是否為 3 的冪次方（即存在整數 x 使得 n = 3^x）。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1)
        {
            return false;
        }
        // 1 是 3 的 0 次方
        else if(n == 1)
        {
            return true;
        }

        // 不斷除以 3，檢查餘數
        while(n > 1)
        {
            if(n % 3 != 0)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // 27 -> true (3^3)
    // 0  -> false
    // 9  -> true (3^2)
    // 45 -> false (雖然能被 3 整除，但不是 3 的冪)
    vector<int> testCases = {27, 0, 9, 45, 1, -3};

    cout << boolalpha; // 使輸出顯示 true/false
    cout << "--- Power of Three Test ---" << endl;

    for (int n : testCases) {
        cout << "Input: " << n << " -> Is Power of Three? " << sol.isPowerOfThree(n) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}