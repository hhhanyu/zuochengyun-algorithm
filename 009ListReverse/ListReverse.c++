#include <bits/stdc++.h>
using namespace std;

// 用于演示按值传递与按引用传递的类
class Number {
public:
    int val;
    Number(int v) : val(v) {}
};

// 值传递演示：参数按值传递，修改形参不影响实参
void f(int a) {
    a = 0;
}

// 指针传递：修改指针本身不影响外部指针，但可修改指针指向的对象
void g1(Number* b) {
    b = nullptr;           // 仅修改局部指针，外部实参指针不变
}

// 指针传递：通过指针修改对象成员
void g2(Number* b) {
    b->val = 6;
}

// 数组名退化为指针，按值传递指针
void g3(int* c) {
    c = nullptr;           // 修改局部指针，外部数组指针不变
}

// 修改数组元素（通过指针解引用）
void g4(int* c) {
    c[0] = 100;
}

// 单链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* nxt) : val(v), next(nxt) {}
};

// 反转单链表
ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* next = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

// 双链表节点
struct DoubleListNode {
    int value;
    DoubleListNode* last;
    DoubleListNode* next;
    DoubleListNode(int v) : value(v), last(nullptr), next(nullptr) {}
};

// 反转双链表
DoubleListNode* reverseDoubleList(DoubleListNode* head) {
    DoubleListNode* pre = nullptr;
    DoubleListNode* next = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }
    return pre;
}

int main() {
    // 基本类型按值传递
    int a = 10;
    f(a);
    cout << a << endl;          // 输出 10

    // 指针传递演示
    Number* b = new Number(5);
    g1(b);
    cout << b->val << endl;     // 输出 5（指针本身未被修改）
    g2(b);
    cout << b->val << endl;     // 输出 6
    delete b;

    // 数组传递演示
    int c[] = {1, 2, 3, 4};
    g3(c);
    cout << c[0] << endl;       // 输出 1
    g4(c);
    cout << c[0] << endl;       // 输出 100

    // 链表反转测试（可选）
    // 例如单链表 1->2->3->nullptr
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3)));
    head = reverseList(head);
    // 遍历：3->2->1
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    // 释放内存（略）

    return 0;
}