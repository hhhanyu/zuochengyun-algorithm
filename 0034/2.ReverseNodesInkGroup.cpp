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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = teamEnd(start, k);
        if (end == nullptr) {
            return head;
        }
        // 第一组很特殊，因为牵扯到换头的问题
        head = end;
        reverse(start, end);
        // 翻转之后 start 变成了上一组的结尾节点
        ListNode* lastTeamEnd = start;
        while (lastTeamEnd->next != nullptr) {
            start = lastTeamEnd->next;
            end = teamEnd(start, k);
            if (end == nullptr) {
                return head;
            }
            reverse(start, end);
            lastTeamEnd->next = end;
            lastTeamEnd = start;
        }
        return head;
    }

private:
    // 当前组的开始节点是 s，往下数 k 个找到当前组的结束节点返回
    ListNode* teamEnd(ListNode* s, int k) {
        while (--k != 0 && s != nullptr) {
            s = s->next;
        }
        return s;
    }

    // 翻转从 s 到 e 之间的节点（不包含 e 后面的节点）
    // 翻转后 s 变成该组的尾节点，原 e 变成该组的头节点
    void reverse(ListNode* s, ListNode* e) {
        e = e->next;
        ListNode* pre = nullptr;
        ListNode* cur = s;
        ListNode* next = nullptr;
        while (cur != e) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        s->next = e;
    }
};