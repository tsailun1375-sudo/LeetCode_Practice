/*
 * 題目：11. Container With Most Water (盛最多水的容器)
 * 連結：https://leetcode.com/problems/container-with-most-water/
 * 難度：Medium
 * 描述：給定一個長度為 n 的整數陣列 height。有 n 條垂線，第 i 條線的兩個端點是 (i, 0) 和 (i, height[i])。
 * 找出其中的兩條線，使得它們與 x 軸共同構成的容器可以容納最多的水。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lg = 0;              // 紀錄最大面積
        int l = height.size();   // 當前寬度
        int r = l - 1;           // 右指標
        int left = 0;            // 左指標
        int h = 0;               // 決定水位的高度

        while(left < r)
        {
            // 每次移動前，寬度會減 1
            l--; 
            
            // 移動較短的那一側，因為只有移動短邊才有可能讓面積變大
            if(height[left] < height[r])
            {
                h = height[left];
                left++;
            }
            else
            {
                h = height[r];
                r--;
            }

            // 計算當前面積並更新最大值 (寬度使用移動前的 l)
            // 你的邏輯中 l-- 先執行了，所以這筆計算對應的是「移動一步後」的間距
            if(h * (l) > lg)
            {
                lg = h * (l);
            }
        }
        return lg; 
    }
};

int main() {
    Solution sol;

    // 測試範例 1
    // height = [1,8,6,2,5,4,8,3,7]
    // 最大面積是 8 和 7 之間，間距 7，高度 7 -> 49
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Test 1: " << sol.maxArea(h1) << " (Expected: 49)" << endl;

    // 測試範例 2
    vector<int> h2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(h2) << " (Expected: 1)" << endl;

    return 0;
}