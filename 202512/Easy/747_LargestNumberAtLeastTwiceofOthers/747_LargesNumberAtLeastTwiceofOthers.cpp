/*
 * 題目：747. Largest Number At Least Twice of Others (至少是其他數字兩倍的最大數)
 * 連結：https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 * 難度：Easy
 * 描述：在一個整數陣列 nums 中，找出最大元素是否至少是陣列中每個其他數字的兩倍。
 * 如果是，則回傳最大元素的索引，否則回傳 -1。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        // 處理陣列長度為 1 的特殊情況
        if (nums.size() == 1) return 0;

        int large = -1, temp = -1;
        // 第一遍：尋找最大值及其位置
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > large)
            {
                large = nums[i];
                temp = i;
            }
        }

        // 第二遍：檢查是否至少為其他數字的兩倍
        for(int i = 0; i < nums.size(); i++)
        {
            // 排除最大值本身，檢查其餘數字
            if(i != temp && large < 2 * nums[i])
            {
                return -1;
            }
        }
        return temp;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // [3, 6, 1, 0] -> 6 是最大值，且 6 >= 2*3, 6 >= 2*1, 6 >= 2*0，回傳索引 1
    // [1, 2, 3, 4] -> 4 是最大值，但 4 < 2*3，回傳 -1
    vector<vector<int>> testCases = {
        {3, 6, 1, 0},
        {1, 2, 3, 4},
        {1},
        {0, 0, 0, 1}
    };

    cout << "--- Dominant Index Test ---" << endl;

    for (auto& nums : testCases) {
        cout << "Input: [";
        for (int i = 0; i < nums.size(); i++) cout << nums[i] << (i == nums.size()-1 ? "" : ", ");
        cout << "] -> Output: " << sol.dominantIndex(nums) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}