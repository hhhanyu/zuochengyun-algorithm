#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* cur = head;
        Node* next = nullptr;

        // 第一步：在每个原节点后面插入一个复制节点
        // 1 -> 2 -> 3 变为 1 -> 1' -> 2 -> 2' -> 3 -> 3'
        while (cur != nullptr) {
            next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }

        // 第二步：利用新老节点的对应关系，设置复制节点的 random 指针
        cur = head;
        Node* copy = nullptr;
        while (cur != nullptr) {
            next = cur->next->next;          // 原链表的下一个节点（隔一个）
            copy = cur->next;                // 复制节点
            copy->random = (cur->random != nullptr) ? cur->random->next : nullptr;
            cur = next;
        }

        // 第三步：拆分链表，恢复原链表并提取复制链表
        Node* ans = head->next;              // 复制链表的头节点
        cur = head;
        while (cur != nullptr) {
            next = cur->next->next;          // 原链表的下一个节点
            copy = cur->next;                // 复制节点
            cur->next = next;                // 恢复原链表
            copy->next = (next != nullptr) ? next->next : nullptr; // 连接复制链表
            cur = next;
        }

        return ans;
    }
};