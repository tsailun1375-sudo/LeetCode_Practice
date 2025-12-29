/*
 * 題目：231. Power of Two (2 的冪次方)
 * 連結：https://leetcode.com/problems/power-of-two/
 * 難度：Easy
 * 描述：給定一個整數 n，請判斷它是否為 2 的冪次方。如果是，回傳 true；否則回傳 false。
 * 2 的冪次方定義為存在一個整數 x 使得 n == 2^x。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1)
        {
            return true;
        }
        else if(n <= 0)
        {
            return false;
        }
        else if(n % 2 != 0)
        {
            return false;
        }

        while(n > 1)
        {
            if(n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // 1 -> true (2^0)
    // 16 -> true (2^4)
    // 3 -> false
    // 0 -> false
    vector<int> testCases = {1, 16, 3, 4, 5, 0, -8};

    cout << boolalpha; // 讓輸出顯示 true/false
    cout << "--- Power of Two Test ---" << endl;

    for (int n : testCases) {
        cout << "Input: " << n << " -> Output: " << sol.isPowerOfTwo(n) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}