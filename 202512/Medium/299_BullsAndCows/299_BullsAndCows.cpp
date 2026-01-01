#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0, temp;
        int sec[10] = {0}, gue[10] = {0};

        // 統計 secret 每個數字出現頻次
        for(int i = 0; i < secret.length(); i++) {
            temp = secret[i] - '0';
            sec[temp] += 1;
        }
        // 統計 guess 每個數字出現頻次
        for(int i = 0; i < guess.length(); i++) {
            temp = guess[i] - '0';
            gue[temp] += 1;
        }

        // 計算兩個集合的交集（即數字正確的總數，不論位置）
        for(int i = 0; i < 10; i++) {
            B += min(sec[i], gue[i]);
        }
        
        // 計算 A 的數量，並從總數中扣除得到 B
        for(int i = 0; i < secret.length(); i++) {
            if(secret[i] == guess[i]) {
                A++;
                B--;
            }
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1
    string secret1 = "1807", guess1 = "7810";
    cout << "Test 1: " << sol.getHint(secret1, guess1) << " (Expected: 1A3B)" << endl;
    
    // 測試範例 2
    string secret2 = "1123", guess2 = "0111";
    cout << "Test 2: " << sol.getHint(secret2, guess2) << " (Expected: 1A1B)" << endl;

    return 0;
}