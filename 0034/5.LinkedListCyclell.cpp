#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;

        // 第一阶段：快慢指针检测是否有环
        while (slow != fast) {
            if (fast->next == nullptr || fast->next->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        // 第二阶段：寻找环的入口
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};