#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

// 自定义比较器：按照节点值升序（小根堆）
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // 注意：优先队列默认是 less，返回 true 表示 a 的优先级低于 b，即值大的优先级低，所以用 > 实现小根堆
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 小根堆
        priority_queue<ListNode*, vector<ListNode*>, Compare> heap;// 指定了比较器，就必须手动补上容器类型（哪怕它就是默认的 vector）
        for (ListNode* head : lists) {// 遍历所有的头
            if (head != nullptr) {
                heap.push(head);
            }
        }
        if (heap.empty()) {// 有序链表全是空的
            return nullptr;
        }
        // 先弹出一个节点作为总头部
        ListNode* h = heap.top();
        heap.pop();
        ListNode* pre = h;// pre指示新链表的尾部，即最后一个加入新链表的节点
        if (pre->next != nullptr) {
            heap.push(pre->next);// 由于原头部弹出做总头部，要更新原链表的头，入堆
        }
        while (!heap.empty()) {
            ListNode* cur = heap.top();
            heap.pop();
            pre->next = cur;// 把cur挂在新链表的尾部
            pre = cur;// 更新pre指示新链表尾部
            if (cur->next != nullptr) {
                heap.push(cur->next);// 把原来cur节点的下一位，即原链表的新头部入堆
            }
        }
        return h;// 返回排好序的总链表的头
    }
};