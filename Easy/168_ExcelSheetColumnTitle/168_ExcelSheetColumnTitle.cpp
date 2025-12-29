/*
 * 題目：168. Excel Sheet Column Title (Excel 欄位名稱)
 * 連結：https://leetcode.com/problems/excel-sheet-column-title/
 * 難度：Easy
 * 描述：給你一個整數 columnNumber，傳回它在 Excel 表中對應的列名稱。
 * 例如：A -> 1, B -> 2, C -> 3 ... Z -> 26, AA -> 27, AB -> 28
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        char temp;
        while(columnNumber >= 1)
        {
            int col = columnNumber % 26;
            // 處理餘數為 0 的特殊情況（即對應 'Z'）
            if(col == 0)
            {
                temp = 26 + 64; // 'Z' 的 ASCII 碼
                columnNumber -= 1; // 關鍵修正：向高位借位
            }
            else
            {
                temp = col + 64; // 1+64='A', 2+64='B'...
            }
            
            // 將字元插入到字串最前面
            ans.insert(0, 1, temp);
            
            // 判斷是否已經處理完畢
            if(columnNumber == 26)
            {
                break;
            }
            columnNumber /= 26;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // 1 -> "A"
    // 28 -> "AB"
    // 701 -> "ZY"
    vector<int> testCases = {1, 28, 701, 2147483647};

    cout << "--- Excel Column Title Test ---" << endl;

    for (int n : testCases) {
        cout << "Number: " << n << " -> Title: " << sol.convertToTitle(n) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}