/*
 * 題目：2. Add Two Numbers (兩數相加)
 * 連結：https://leetcode.com/problems/add-two-numbers/
 * 難度：Medium
 * 描述：給你兩個非空的鏈結串列，表示兩個非負整數。數字是以「逆序」儲存的，每個節點包含一個位數。
 * 將這兩個數相加，並以鏈結串列的形式回傳。
 */

#include <iostream>
#include <vector>

using namespace std;

// 定義單向鏈結串列的節點結構
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        return length;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        ListNode* current1 = l1;
        ListNode* current2 = l2;

        // 第一步：將兩條鏈結串列的對應位數相加，存入較長的那一條
        while(current1 != nullptr && current2 != nullptr) {
            if(len1 >= len2) {
                current1->val += current2->val;
                current1 = current1->next;
                current2 = current2->next;
            } else {
                current2->val += current1->val;
                current1 = current1->next;
                current2 = current2->next;
            }
        }
        
        // 第二步：處理進位邏輯
        ListNode* current3 = l1;
        ListNode* current4 = l2;

        if(len1 >= len2) {
            while(current3 != nullptr) {
                if(current3->val > 9) {
                    current3->val -= 10; 
                    if (current3->next == nullptr) {
                        current3->next = new ListNode(0); 
                    }               
                    current3->next->val += 1;
                }
                current3 = current3->next;
            }
            return l1;
        } else {
            while(current4 != nullptr) {
                if(current4->val > 9) {
                    current4->val -= 10; 
                    if (current4->next == nullptr) {
                        current4->next = new ListNode(0); 
                    }               
                    current4->next->val += 1;
                }
                current4 = current4->next;
            }
            return l2;
        }
    }
};

// 輔助函式：將陣列轉為鏈結串列
ListNode* createList(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

// 輔助函式：列印鏈結串列
void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // 測試範例 1: (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
    // 表示 342 + 465 = 807
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    cout << "Test 1: ";
    ListNode* result1 = sol.addTwoNumbers(l1, l2);
    printList(result1);

    // 測試範例 2: (9 -> 9 -> 9) + (1) = 0 -> 0 -> 0 -> 1
    // 表示 999 + 1 = 1000
    ListNode* l3 = createList({9, 9, 9});
    ListNode* l4 = createList({1});

    cout << "Test 2: ";
    ListNode* result2 = sol.addTwoNumbers(l3, l4);
    printList(result2);

    return 0;
}