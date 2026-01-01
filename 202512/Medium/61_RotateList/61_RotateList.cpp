#include <iostream>
#include <vector>

using namespace std;

// 定義 ListNode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        
        // 1. 找結尾並計算長度
        ListNode* tail = head;
        int l = 1;
        while(tail->next != nullptr) {
            tail = tail->next;
            l++;
        }
        
        // 2. 首尾相連成環
        tail->next = head;
        
        // 3. 計算實際位移
        k %= l;
        int stepsToNewHead = l - k;
        
        // 4. 找到新的頭與新的尾
        ListNode* new_head = head;
        for(int i = 0; i < stepsToNewHead; i++) {
            new_head = new_head->next;
        }

        ListNode* new_tail = new_head;
        for(int i = 1; i < l; i++) {
            new_tail = new_tail->next;
        }
        
        // 5. 斷開環
        new_tail->next = nullptr;

        return new_head;
    }
};

// 輔助函式
ListNode* createList(vector<int> nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* head = createList({1, 2, 3, 4, 5});
    
    cout << "Original List: ";
    printList(head);
    
    int k = 2;
    ListNode* result = sol.rotateRight(head, k);
    
    cout << "Rotated " << k << " times: ";
    printList(result);

    return 0;
}