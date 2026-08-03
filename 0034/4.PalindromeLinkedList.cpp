#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // 1. 找中点（slow 最终指向中点，偶数长度时指向上中点）
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. 反转后半部分链表（从中点之后开始）
        ListNode* pre = slow;          // 前驱，初始指向中点
        ListNode* cur = pre->next;     // 当前要反转的节点
        ListNode* next = nullptr;
        pre->next = nullptr;           // 切断前半部分

        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 此时 pre 指向原链表最后一个节点，即反转后的头

        // 3. 比较前半部分和反转后的后半部分
        bool ans = true;
        ListNode* left = head;
        ListNode* right = pre;         // 从尾部向前
        while (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                ans = false;
                break;
            }
            left = left->next;
            right = right->next;
        }

        // 4. 恢复链表（反转回来，保持原样，非必须但规范）
        cur = pre->next;
        pre->next = nullptr;
        next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return ans;
    }
};