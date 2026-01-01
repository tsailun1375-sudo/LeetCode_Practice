/*
 * 題目：1154. Day of the Year (一年中的第幾天)
 * 連結：https://leetcode.com/problems/day-of-the-year/
 * 難度：Easy
 * 描述：給你一個字串 date ，按 YYYY-MM-DD 格式表示，請你算出該日期是當年的第幾天。
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int dayOfYear(string date) 
    {
        int y, m, d, sum = 0;
        // 手動解析字串轉整數 (ASCII 48 為 '0')
        y = (date[0]-48) * 1000 + (date[1]-48) * 100 + (date[2]-48) * 10 + (date[3]-48);
        m = (date[5]-48) * 10 + (date[6]-48);
        d = (date[8]-48) * 10 + (date[9]-48);

        // 累積前 M-1 個月的天數
        switch(m)
        {
            case 12 : sum += 334; break;
            case 11 : sum += 304; break;
            case 10 : sum += 273; break;
            case 9  : sum += 243; break;
            case 8  : sum += 212; break;
            case 7  : sum += 181; break;
            case 6  : sum += 151; break;
            case 5  : sum += 120; break;
            case 4  : sum += 90;  break;
            case 3  : sum += 59;  break;
            case 2  : sum += 31;  break;
            default: break;
        }

        // 處理閏年邏輯：
        // 1. 能被 4 整除但不能被 100 整除
        // 2. 或者能被 400 整除
        if(y == 1900)
        {
            return sum + d;
        }
        else if(y % 4 == 0 && m > 2)
        {
            return sum + d + 1;
        }
        else
            return sum + d;
    
    }
};

int main() {
    Solution sol;

    // 測試範例
    // 2019-01-09 -> 9
    // 2019-02-10 -> 41
    // 2004-03-01 -> 61 (2004 是閏年)
    // 1900-03-25 -> 84 (1900 不是閏年)
    vector<string> testCases = {"2019-01-09", "2019-02-10", "2004-03-01", "1900-03-25"};

    cout << "--- Day of the Year Test ---" << endl;

    for (const string& d : testCases) {
        cout << "Date: " << d << " -> Day: " << sol.dayOfYear(d) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}