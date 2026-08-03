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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int n = 0;// 记录链表长度，来设置步长
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }
        // l1,r1 每组的左部分
        // l2,r2 每组的右部分
        // next 下一组开头
        // lastTeamEnd 上一组结尾
        ListNode *l1, *r1, *l2, *r2, *next, *lastTeamEnd;
        ListNode *start = nullptr, *end = nullptr;   // 存储合并后的头尾

        for (int step = 1; step < n; step <<= 1) {
            // 第一组单独处理，决定链表头
            l1 = head;
            r1 = findEnd(l1, step);
            l2 = r1->next;
            r2 = findEnd(l2, step);
            next = r2->next;
            r1->next = nullptr;
            r2->next = nullptr;

            merge(l1, r1, l2, r2, start, end);
            head = start;
            lastTeamEnd = end;

            while (next != nullptr) {
                l1 = next;
                r1 = findEnd(l1, step);
                l2 = r1->next;
                if (l2 == nullptr) {
                    lastTeamEnd->next = l1;
                    break;
                }
                r2 = findEnd(l2, step);
                next = r2->next;
                r1->next = nullptr;
                r2->next = nullptr;

                merge(l1, r1, l2, r2, start, end);
                lastTeamEnd->next = start;
                lastTeamEnd = end;
            }
        }
        return head;
    }

private:
    // 包括 s 在内，往后数 k 个节点，返回第 k 个节点；若不够，返回最后一个非空节点
    ListNode* findEnd(ListNode* s, int k) {
        while (s->next != nullptr && --k != 0) {
            s = s->next;
        }
        return s;
    }

    // 合并两个有序链表 l1...r1 和 l2...r2（均已切断），合并后通过 start 和 end 返回头尾
    void merge(ListNode* l1, ListNode* r1, ListNode* l2, ListNode* r2,
               ListNode*& start, ListNode*& end) {
        ListNode* pre;
        if (l1->val <= l2->val) {
            start = l1;
            pre = l1;
            l1 = l1->next;
        } else {
            start = l2;
            pre = l2;
            l2 = l2->next;
        }

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) {
            pre->next = l1;
            end = r1;
        } else {
            pre->next = l2;
            end = r2;
        }
    }
};