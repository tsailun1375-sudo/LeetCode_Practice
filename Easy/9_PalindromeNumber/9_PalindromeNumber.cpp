/*
 * 題目：9. Palindrome Number (迴文整數)
 * 連結：https://leetcode.com/problems/palindrome-number/
 * 難度：Easy
 * 描述：判斷一個整數是否為迴文數。迴文數是指正序和倒序讀起來都一樣的整數。
 * 注意：負數（如 -121）倒過來是 121-，因此不是迴文。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // 將整數轉換為字串
        string a = to_string(x);
        int l = a.length();
        
        // 雙指標概念：比較頭尾字元是否對稱
        for(int i = 0; i < (l/2); i++)
        {
            if( a[i] != a[l-i-1])
            {
                return false;
            }
        }
       
        return true;        
    }
};

int main() {
    Solution sol;
    
    // 準備測試範例
    // 121 -> true
    // -121 -> false (負號導致不對稱)
    // 10 -> false
    vector<int> testCases = {121, -121, 10, 12321, 0};
    
    cout << boolalpha; // 讓輸出顯示 true/false 而不是 1/0
    for (int x : testCases) {
        cout << "Input: " << x << " -> Is Palindrome? " << sol.isPalindrome(x) << endl;
    }

    return 0;
}