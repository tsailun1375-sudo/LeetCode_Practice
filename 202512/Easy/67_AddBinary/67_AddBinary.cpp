/*
 * 題目：67. Add Binary (二進位加法)
 * 連結：https://leetcode.com/problems/add-binary/
 * 難度：Easy
 * 描述：給定兩個二進位字串 a 和 b，傳回它們的和（同樣以二進位字串形式）。
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<char> rot(vector<char> a)
    {
        int l = a.size();
        int left = 0;
        int right = l - 1;

        while(left < right)
        {
            swap(a[left], a[right]);
            left++;
            right--;
        }
        return a;
    }
    
public:
    string addBinary(string a, string b) {
        
        vector<char> x(a.begin(), a.end());
        vector<char> y(b.begin(), b.end());

        // 確保 x 永遠是較長的那個字串，方便後續迴圈處理
        if (y.size() > x.size())
        {
             swap(x, y);
        }      

        x = rot(x);
        y = rot(y);

        int carry = 0;        
        for (size_t i = 0; i < x.size(); ++i) 
        { 
            int sum = (x[i] - '0') + carry;
            
            if (i < y.size()) 
            {
                sum += (y[i] - '0');
            }
            carry = sum / 2;     
            int digit = sum % 2; 
            
            x[i] = digit + '0'; 
        }
        
        // 若最後還有進位，需多加一位
        if (carry > 0) {
            x.push_back('1');
        }

        // 再次反轉回正確順序
        x = rot(x);

        string ans(x.begin(), x.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // 測試範例
    // "11" + "1" = "100"
    // "1010" + "1011" = "10101"
    struct TestCase {
        string a;
        string b;
    };

    vector<TestCase> tests = {
        {"11", "1"},
        {"1010", "1011"},
        {"0", "0"},
        {"1111", "1111"}
    };

    cout << "--- Binary Addition Test ---" << endl;

    for (const auto& t : tests) {
        cout << "Input: a = " << t.a << ", b = " << t.b 
             << " -> Output: " << sol.addBinary(t.a, t.b) << endl;
    }

    cout << "--- Test Finished ---" << endl;

    return 0;
}