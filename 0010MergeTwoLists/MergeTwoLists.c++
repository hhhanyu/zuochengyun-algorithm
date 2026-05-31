// 将两个升序链表合并为一个新的升序链表并返回
// 测试链接 : https://leetcode.cn/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return head1 == nullptr ? head2 : head1;
        }
        ListNode* head = head1->val <= head2->val ? head1 : head2;
        ListNode* cur1 = head->next;
        ListNode* cur2 = head == head1 ? head2 : head1;
        ListNode* pre = head;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                pre->next = cur1;
                cur1 = cur1->next;
            } else {
                pre->next = cur2;
                cur2 = cur2->next;
            }
            pre = pre->next;
        }
        pre->next = cur1 != nullptr ? cur1 : cur2;
        return head;
    }
};