/*
 * 題目：1. Two Sum
 * 連結：https://leetcode.com/problems/two-sum/
 * 難度：Easy
 * 描述：在陣列中找到兩個數，其和等於目標值 target，並返回其索引。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int ans = target - nums[i];
            for(int j = i + 1; j < n; j++) {
                if(ans == nums[j]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution sol;
    
    // 測試範例
    vector<int> testNums = {2, 7, 11, 15};
    int testTarget = 9;
    
    vector<int> result = sol.twoSum(testNums, testTarget);
    
    if (result.size() == 2) {
        cout << "Index found: [" << result[0] << ", " << result[1] << "]" << endl;
        cout << "Values: " << testNums[result[0]] << " + " << testNums[result[1]] 
             << " = " << testTarget << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}