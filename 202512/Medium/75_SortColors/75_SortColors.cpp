#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0, l = nums.size();
        
        // 第一遍：統計數量
        for(int i = 0; i < l; i++) {
            if(nums[i] == 0) r++;
            else if(nums[i] == 1) w++;
            else if(nums[i] == 2) b++;
        }
        
        // 覆寫原陣列 (優化：不使用 clear + push_back，直接修改)
        int index = 0;
        for(int i = 0; i < r; i++) nums[index++] = 0;
        for(int i = 0; i < w; i++) nums[index++] = 1;
        for(int i = 0; i < b; i++) nums[index++] = 2;
    }
};

int main() {
    Solution sol;
    vector<int> test = {2, 0, 2, 1, 1, 0};
    
    cout << "Before sort: ";
    for(int n : test) cout << n << " ";
    cout << endl;
    
    sol.sortColors(test);
    
    cout << "After sort:  ";
    for(int n : test) cout << n << " ";
    cout << endl;

    return 0;
}