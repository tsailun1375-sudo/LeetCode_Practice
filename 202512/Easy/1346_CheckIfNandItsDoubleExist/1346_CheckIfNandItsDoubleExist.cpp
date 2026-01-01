#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // 根據題目限制，數值在 -1000 到 1000 之間，所以開 2001 個空間
        int l[2002] = {0}; 
        for(int i = 0; i < arr.size(); i++)
        {
            l[arr[i] + 1000] += 1;
        }

        // 處理 0 的特殊情況：必須出現兩次以上
        if(l[1000] >= 2)
        {
            return true;
        }         

        for(int i = 0; i < arr.size(); i++)
        {
            // 計算兩倍值在桶子裡的索引位置
            int temp = (arr[i] * 2) + 1000;
            
            // 確保兩倍值不會超出桶子的索引範圍 (-1000 ~ 1000)
            if(arr[i] <= 500 && arr[i] >= -500)
            {
                // 如果兩倍值存在，且當前值不是 0 (0 已在上面處理過)
                if(l[temp] != 0 && arr[i] != 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // 測試範例 1: 10 是 5 的兩倍 -> true
    vector<int> arr1 = {10, 2, 5, 3};
    // 測試範例 2: 沒有兩倍關係 -> false
    vector<int> arr2 = {3, 1, 7, 11};
    // 測試範例 3: 兩個 0 -> true
    vector<int> arr3 = {0, 0};

    cout << boolalpha;
    cout << "Test 1 [10, 2, 5, 3]: " << sol.checkIfExist(arr1) << endl;
    cout << "Test 2 [3, 1, 7, 11]: " << sol.checkIfExist(arr2) << endl;
    cout << "Test 3 [0, 0]: " << sol.checkIfExist(arr3) << endl;

    return 0;
}