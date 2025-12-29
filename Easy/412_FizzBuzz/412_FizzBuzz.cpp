/*
 * 題目：412. Fizz Buzz
 * 連結：https://leetcode.com/problems/fizz-buzz/
 * 難度：Easy
 * 描述：給你一個整數 n，從 1 到 n 傳回一個字串陣列答案（下標從 1 開始），其中：
 * - 如果 i 同時是 3 和 5 的倍數，答案是 "FizzBuzz"。
 * - 如果 i 是 3 的倍數，答案是 "Fizz"。
 * - 如果 i 是 5 的倍數，答案是 "Buzz"。
 * - 如果以上條件都不滿足，答案是該數字 i 的字串格式。
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++)
        {
            if(i % 15 == 0)
            {
                ans.push_back("FizzBuzz");
            } else if(i % 3 == 0)
            {
                ans.push_back("Fizz");
            } else if(i % 5 == 0)
            {
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 15; 
    vector<string> result = sol.fizzBuzz(n);
    cout << "Test Result for n = " << n << ":" << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    cout << "--- End of output ---" << endl;

    return 0;
}