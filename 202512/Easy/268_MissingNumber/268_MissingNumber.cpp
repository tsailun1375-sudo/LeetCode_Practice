/*
 * 題目：268. Missing Number (缺失數字)
 * 連結：https://leetcode.com/problems/missing-number/
 * 難度：Easy
 * 描述：給定一個包含 [0, n] 中 n 個數的陣列 nums ，找出 [0, n] 這個範圍內沒有出現在陣列中的那個數。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = nums.size();
        // 根據題目限制，n 最大通常為 10000
        int t[10001] = {0};
        
        // 第一遍：記錄出現過的數字
        for(int i = 0; i < l; i++)
        {
            t[nums[i]] += 1;
        }
        
        // 第二遍：從 0 檢查到 l (因為總共有 l+1 個可能的數字)
        for(int i = 0; i <= l; i++)
        {
            if(t[i] == 0)
            {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1: n=3, 應有 0,1,2,3，缺少 2
    vector<int> nums1 = {3, 0, 1};
    // 測試範例 2: n=2, 應有 0,1,2，缺少 2
    vector<int> nums2 = {0, 1};
    // 測試範例 3: n=9, 缺少 8
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    cout << "--- Missing Number Test ---" << endl;
    cout << "Test 1 [3, 0, 1]: " << sol.missingNumber(nums1) << " (Expected: 2)" << endl;
    cout << "Test 2 [0, 1]:    " << sol.missingNumber(nums2) << " (Expected: 2)" << endl;
    cout << "Test 3:           " << sol.missingNumber(nums3) << " (Expected: 8)" << endl;

    return 0;
}