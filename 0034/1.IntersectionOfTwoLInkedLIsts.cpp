#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* a = headA;
        ListNode* b = headB;
        int diff = 0;

        // 计算链表 A 的长度（减去头节点后的节点数）
        while (a->next != nullptr) {
            a = a->next;
            diff++;
        }

        // 计算链表 B 的长度（减去头节点后的节点数），并从 diff 中减去
        while (b->next != nullptr) {
            b = b->next;
            diff--;
        }

        // 如果尾节点不同，则链表不相交
        if (a != b) {
            return nullptr;
        }

        // 让 a 指向较长的链表，b 指向较短的链表
        if (diff >= 0) {
            a = headA;
            b = headB;
        } else {
            a = headB;
            b = headA;
        }

        // 将较长链表的指针向前移动 diff 步
        diff = abs(diff);
        while (diff-- != 0) {
            a = a->next;
        }

        // 同时移动两个指针，直到它们相遇
        while (a != b) {
            a = a->next;
            b = b->next;
        }

        return a;
    }
};