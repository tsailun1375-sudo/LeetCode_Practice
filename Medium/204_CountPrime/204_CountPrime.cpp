/*
 * 題目：204. Count Primes
 * 連結：https://leetcode.com/problems/count-primes/
 * 難度：Medium
 * 描述：計算小於非負整數 n 的質數數量。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // 建立一個布林陣列，預設全部都是質數 (true)
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false; // 0 和 1 表示是否為質數
        
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // 如果 i 是質數，則把 i 的倍數全部標記為非質數
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // 統計剩下為 true 的個數
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    int n = 10;
    int result = sol.countPrimes(n);
    
    // 輸出結果
    cout << "Input n: " << n << endl;
    cout << "Number of primes less than " << n << ": " << result << endl;
    cout << "Expected: 4 (2, 3, 5, 7)" << endl;

    return 0;
}