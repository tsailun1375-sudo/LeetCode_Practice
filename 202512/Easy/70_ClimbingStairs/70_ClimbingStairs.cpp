/*
 * 題目：70. Climbing Stairs (爬樓梯)
 * 連結：https://leetcode.com/problems/climbing-stairs/
 * 難度：Easy
 * 描述：假設你正在爬樓梯。需要 n 階你才能到達樓頂。
 * 每次你可以爬 1 或 2 個臺階。你有多少種不同的方法可以爬到樓頂呢？
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 處理當 n 很小時的情況，避免陣列存取問題
        if (n <= 2) return n;

        // 題目給定 n 範圍通常在 1~45
        int a[46];
        a[1] = 1;
        a[2] = 2;

        for(int i = 3; i <= n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        
        return a[n];
    }
};

int main() {
    Solution sol;

    // 測試範例
    // n = 2 -> 2 (1+1, 2)
    // n = 3 -> 3 (1+1+1, 1+2, 2+1)
    // n = 4 -> 5
    vector<int> testCases = {2, 3, 4, 5, 10, 45};

    cout << "--- Climbing Stairs Test ---" << endl;

    for (int n : testCases) {
        cout << "Steps: " << n << " -> Ways: " << sol.climbStairs(n) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}