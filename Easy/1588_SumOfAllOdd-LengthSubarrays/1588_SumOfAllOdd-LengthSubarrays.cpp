/*
 * 題目：1588. Sum of All Odd-Length Subarrays (所有奇數長度子陣列的和)
 * 連結：https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
 * 難度：Easy
 * 描述：給你一個正整數陣列 arr ，請你計算所有可能的奇數長度子陣列的和。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        int sum = 0;

        // i 為子陣列的起始點
        for(int i = 0; i < arr.size(); i++)
        {
            int l = 0; // l 為當前子陣列相對於 i 的偏移量 (長度 - 1)
            // 確保子陣列結尾不超過陣列範圍
            while(i + l < arr.size())
            {
                // 遍歷當前奇數長度的子陣列並加總
                for(int j = i; j <= i + l; j++)
                {
                    sum += arr[j];
                }
                // l 每次加 2，確保長度 (l+1) 永遠是奇數 (1, 3, 5...)
                l += 2;
            }
        }
        
        return sum;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // [1, 4, 2, 5, 3] 
    // 長度 1: [1], [4], [2], [5], [3] (和 15)
    // 長度 3: [1,4,2], [4,2,5], [2,5,3] (和 26)
    // 長度 5: [1,4,2,5,3] (和 15)
    // 總和: 15 + 26 + 15 = 58
    vector<int> arr1 = {1, 4, 2, 5, 3};
    vector<int> arr2 = {1, 2}; // 只有長度 1: [1], [2] (和 3)

    cout << "--- Sum of Odd-Length Subarrays Test ---" << endl;
    cout << "Input: [1, 4, 2, 5, 3] -> Output: " << sol.sumOddLengthSubarrays(arr1) << endl;
    cout << "Input: [1, 2]          -> Output: " << sol.sumOddLengthSubarrays(arr2) << endl;
    cout << "--- Test Finished ---" << endl;

    return 0;
}