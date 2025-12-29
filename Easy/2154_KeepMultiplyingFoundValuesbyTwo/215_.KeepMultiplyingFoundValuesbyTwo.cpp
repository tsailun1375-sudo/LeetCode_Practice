/*
 * 題目：2154. Keep Multiplying Found Values by Two
 * 連結：https://leetcode.com/problems/keep-multiplying-found-values-by-two/
 * 難度：Easy
 * 描述：在 nums 中尋找 original。如果找到，將 original 乘以 2 並重複此過程；否則，回傳最終的 original。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // 建立一個計數桶，根據題目限制，數值最大為 1000
        int temp[1001] = {0};
        for(int i = 0; i < nums.size(); i++)
        {
            temp[nums[i]] += 1;
        }

        // 當 original 還在桶子裡（代表存在於 nums）就繼續翻倍
        while(original <= 1000 && temp[original] != 0)
        {
            original *= 2;
        }
        
        return original;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // nums = [5,3,6,1,12], original = 3
    // 3 存在 -> 6
    // 6 存在 -> 12
    // 12 存在 -> 24
    // 24 不存在 -> 回傳 24
    vector<int> nums1 = {5, 3, 6, 1, 12};
    int ori1 = 3;

    vector<int> nums2 = {2, 7, 9};
    int ori2 = 4;

    cout << "--- Keep Multiplying Test ---" << endl;
    cout << "Test 1: " << sol.findFinalValue(nums1, ori1) << " (Expected: 24)" << endl;
    cout << "Test 2: " << sol.findFinalValue(nums2, ori2) << " (Expected: 4)" << endl;
    cout << "--- Test Finished ---" << endl;

    return 0;
}