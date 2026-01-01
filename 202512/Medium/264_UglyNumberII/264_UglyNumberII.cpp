#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> a;
        a.push_back(1);
        int n2 = 0, n3 = 0, n5 = 0;
        
        while(a.size() < n) // 修改為 < n 確保剛好存到第 n 個
        {
            int m2 = a[n2] * 2;
            int m3 = a[n3] * 3;
            int m5 = a[n5] * 5;

            int next = min({m2, m3, m5});
            a.push_back(next);

            // 如果 next 等於某個生產線的結果，該生產線指針就往前移
            if(next == m2) n2++;
            if(next == m3) n3++;
            if(next == m5) n5++;
        }
        return a[n - 1];
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1
    int n1 = 10;
    cout << "Test 1 (n=10): " << sol.nthUglyNumber(n1) << " (Expected: 12)" << endl;
    
    // 測試範例 2
    int n2 = 1;
    cout << "Test 2 (n=1): " << sol.nthUglyNumber(n2) << " (Expected: 1)" << endl;

    return 0;
}