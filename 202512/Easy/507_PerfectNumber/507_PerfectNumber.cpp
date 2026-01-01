/*
 * 題目：507. Perfect Number (完美數)
 * 連結：https://leetcode.com/problems/perfect-number/
 * 難度：Easy
 * 描述：對於一個正整數，如果它等於除了它自身以外的所有正因子之和，它就是一個「完美數」。
 * 例如：28 = 1 + 2 + 4 + 7 + 14
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        // 1 不是完美數（正因子只有 1，除了自身以外沒有其他因子）
        if(num == 1) return false;
        
        int total = 1; // 1 必定是所有大於 1 數字的因子
        bool same = false;
        vector<int> a, b;

        // 只需要檢查到 sqrt(num)
        for(int i = 2; i * i <= num; i++)
        {
            if( num % i == 0)
            {
                a.push_back(i);
                b.push_back(num/i);
                // 如果是完全平方根，標記起來避免重複加總
                if(i * i == num)
                {
                    same = true;
                }
            }
        }

        // 加總成對的因子
        for(int i = 0; i < a.size(); i++)
        {
            total = total + a[i] + b[i];
        }

        // 如果是完全平方數，會重複加到兩次，需扣掉一個
        if(same) total -= b[a.size() - 1];

        return total == num;
    }
};

int main() {
    Solution sol;
    
    // 測試範例
    // 28: 1+2+4+7+14 = 28 -> true
    // 6: 1+2+3 = 6 -> true
    // 496: 1+2+4+8+16+31+62+124+248 = 496 -> true
    // 10: 1+2+5 = 8 -> false
    vector<int> testCases = {28, 6, 496, 8128, 10, 1};

    cout << boolalpha;
    cout << "--- Perfect Number Test ---" << endl;
    for (int n : testCases) {
        cout << "Input: " << n << " -> " << sol.checkPerfectNumber(n) << endl;
    }

    return 0;
}