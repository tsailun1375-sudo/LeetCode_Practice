#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        if (l == 0) return;
        k %= l;
        if (k == 0) return;

        // 預留空間減少重新分配次數
        nums.reserve(l * 2);
        // 將自己接在後面：[1,2,3] -> [1,2,3,1,2,3]
        nums.insert(nums.end(), nums.begin(), nums.end());
        
        // 截取正確的部分
        // 例如 [1,2,3,4,5], k=2 -> 想要 [4,5,1,2,3]
        // 倍增後 [1,2,3,4,5,1,2,3,4,5]
        // 刪除尾部多餘的
        nums.erase(nums.begin() + (2 * l - k), nums.end());
        // 刪除頭部多餘的
        nums.erase(nums.begin(), nums.begin() + (l - k));
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    sol.rotate(nums1, k1);
    cout << "Test 1: ";
    for(int n : nums1) cout << n << " "; // Expected: 5 6 7 1 2 3 4
    cout << endl;
    
    // 測試範例 2
    vector<int> nums2 = {-1, -100, 3, 99};
    int k2 = 2;
    sol.rotate(nums2, k2);
    cout << "Test 2: ";
    for(int n : nums2) cout << n << " "; // Expected: 3 99 -1 -100
    cout << endl;

    return 0;
}