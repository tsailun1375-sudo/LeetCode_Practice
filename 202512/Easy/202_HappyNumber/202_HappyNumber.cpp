#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        // 只要還沒抵達 1，就繼續賽跑
        while(slow > 1 && fast > 1)
        {
            // 慢指標走一步
            slow = getNext(slow);

            // 快指標走兩步
            fast = getNext(getNext(fast));

            // 如果相遇了且不是 1，代表進入了死循環
            if(fast == slow && fast != 1)
            {
                return false;
            }
        }
        return true;
    }

private:
    // 封裝「各個位數平方和」的邏輯，讓程式碼更乾淨
    int getNext(int num) {
        int sum = 0;
        while(num > 0) {
            int d = num % 10;
            sum += d * d;
            num /= 10;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    
    int test1 = 19;
    cout << "Test 19: " << (sol.isHappy(test1) ? "Happy!" : "Not Happy") << " (Expected: Happy!)" << endl;
    
    int test2 = 2;
    cout << "Test 2: " << (sol.isHappy(test2) ? "Happy!" : "Not Happy") << " (Expected: Not Happy)" << endl;

    return 0;
}