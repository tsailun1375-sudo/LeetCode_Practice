#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 處理溢位特殊情況
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // 目前暫時使用內建除法
        int a = dividend / divisor;
        return a;
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1
    cout << "Test 1 (10 / 3): " << sol.divide(10, 3) << " (Expected: 3)" << endl;
    
    // 測試範例 2 (處理溢位)
    cout << "Test 2 (INT_MIN / -1): " << sol.divide(INT_MIN, -1) << " (Expected: 2147483647)" << endl;
    
    // 測試範例 3
    cout << "Test 3 (7 / -3): " << sol.divide(7, -3) << " (Expected: -2)" << endl;

    return 0;
}