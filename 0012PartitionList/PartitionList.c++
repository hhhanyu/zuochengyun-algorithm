// 给你一个链表的头节点 head 和一个特定值 x
// 请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置
// 测试链接 : https://leetcode.cn/problems/partition-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* next = nullptr;
        ListNode* LeftHead = nullptr;
        ListNode* LeftTail = nullptr;
        ListNode* RightHead = nullptr;
        ListNode* RightTail = nullptr;
        
        while (head != nullptr) {
            next = head->next;
            head->next = nullptr;//不要忘记置空；切断当前节点与原始链表中后续节点的连接
            if (head->val < x) {
                if (LeftHead == nullptr) {
                    LeftHead = head;
                } else {
                    LeftTail->next = head;
                }
                LeftTail = head;
            } else {
                if (RightHead == nullptr) {
                    RightHead = head;
                } else {
                    RightTail->next = head;
                }
                RightTail = head;
            }
            head = next;
        }

        if (LeftHead == nullptr)return RightHead;//如果左链表是空的，直接返回右链表头；

        LeftTail->next = RightHead;//即使右链表为空，不影响左链表头返回
        return LeftHead;
    }
};