// 给你两个非空的链表，表示两个非负的整数
// 它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 测试链接：https://leetcode.cn/problems/add-two-numbers/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        ListNode* ans = nullptr;//ans为要返回的新链表的头
        ListNode* cur = nullptr;//cur表示当下节点
        int carry = 0;//carry表示进位
        
        while (h1 != nullptr || h2 != nullptr) {//两链表都空时，停止循环
            int sum = (h1 == nullptr ? 0 : h1->val) 
                    + (h2 == nullptr ? 0 : h2->val) 
                    + carry;
            int val = sum % 10;//当前节点的值
            carry = sum / 10;//进位
            
            if (ans == nullptr) {
                ans = new ListNode(val);
                cur = ans;
            } else {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
            
            if (h1 != nullptr) h1 = h1->next;//进行下一节点的合并
            if (h2 != nullptr) h2 = h2->next;
        }
        
        if (carry == 1) {
            cur->next = new ListNode(1);//最后进位为1，此时已跳出循环，故单独加上最后的进位
        }
        
        return ans;
    }
};