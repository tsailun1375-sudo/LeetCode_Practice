/*
 * 題目：136. Single Number (只出現一次的數字)
 * 連結：https://leetcode.com/problems/single-number/
 * 難度：Easy
 * 描述：給定一個非空整數陣列，除了某個元素只出現一次以外，其餘每個元素均出現兩次。找出那個只出現了一次的元素。
 * 進階：你的演算法應該具有線性時間複雜度 (O(n))。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int l = nums.size();
        // 假設題目數值範圍在 -3000 到 3000 之間
        // 我們開一個足夠大的陣列來存放計數
        int arr[60001] = {0}; 
        
        for(int i = 0; i < l; i++)
        {
            int t = nums[i];
            // 使用偏移量處理負數索引
            arr[t + 3000] += 1;
        }
        
        // 遍歷計數陣列找尋出現次數為 1 的數字
        for(int i = 0; i < 60001; i++)
        {
            if(arr[i] == 1)
            {
                return i - 3000;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // [2, 2, 1] -> 1
    // [4, 1, 2, 1, 2] -> 4
    // [1] -> 1
    vector<vector<int>> testCases = {
        {2, 2, 1},
        {4, 1, 2, 1, 2},
        {1}
    };

    cout << "--- Single Number Test ---" << endl;

    for (auto& nums : testCases) {
        cout << "Input: [";
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << (i == nums.size()-1 ? "" : ",");
        cout << "] -> Output: " << sol.singleNumber(nums) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}