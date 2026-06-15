#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 先序打印所有节点，非递归版
void preOrder(TreeNode* head) {
    if (head != nullptr) {
        stack<TreeNode*> stk;
        stk.push(head);
        while (!stk.empty()) {
            head = stk.top(); stk.pop();
            cout << head->val << " ";
            if (head->right != nullptr) stk.push(head->right);
            if (head->left != nullptr) stk.push(head->left);
        }
        cout << endl;
    }
}

// 中序打印所有节点，非递归版
void inOrder(TreeNode* head) {
    if (head != nullptr) {
        stack<TreeNode*> stk;
        while (!stk.empty() || head != nullptr) {
            if (head != nullptr) {
                stk.push(head);
                head = head->left;
            } else {
                head = stk.top(); stk.pop();
                cout << head->val << " ";
                head = head->right;
            }
        }
        cout << endl;
    }
}

// 后序打印所有节点，非递归版（两个栈）
void posOrderTwoStacks(TreeNode* head) {
    if (head != nullptr) {
        stack<TreeNode*> stk, collect;
        stk.push(head);
        while (!stk.empty()) {
            head = stk.top(); stk.pop();
            collect.push(head);
            if (head->left != nullptr) stk.push(head->left);
            if (head->right != nullptr) stk.push(head->right);
        }
        while (!collect.empty()) {
            cout << collect.top()->val << " ";
            collect.pop();
        }
        cout << endl;
    }
}

// 后序打印所有节点，非递归版（一个栈）
void posOrderOneStack(TreeNode* h) {
    if (h != nullptr) {
        stack<TreeNode*> stk;
        stk.push(h);
        // h 的含义：上一次打印的节点（初始为头节点，但从未打印过，所以实际用 nullptr 更安全）
        TreeNode* lastPrinted = nullptr;
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            if (cur->left != nullptr && lastPrinted != cur->left && lastPrinted != cur->right) {
                stk.push(cur->left);
            } else if (cur->right != nullptr && lastPrinted != cur->right) {
                stk.push(cur->right);
            } else {
                cout << cur->val << " ";
                lastPrinted = stk.top(); stk.pop();
            }
        }
        cout << endl;
    }
}

// 先序遍历，返回 vector（LeetCode）
vector<int> preorderTraversal(TreeNode* head) {
    vector<int> ans;
    if (head != nullptr) {
        stack<TreeNode*> stk;
        stk.push(head);
        while (!stk.empty()) {
            head = stk.top(); stk.pop();
            ans.push_back(head->val);
            if (head->right != nullptr) stk.push(head->right);
            if (head->left != nullptr) stk.push(head->left);
        }
    }
    return ans;     
}

// 中序遍历，返回 vector（LeetCode）
vector<int> inorderTraversal(TreeNode* head) {
    vector<int> ans;
    if (head != nullptr) {
        stack<TreeNode*> stk;
        while (!stk.empty() || head != nullptr) {
            if (head != nullptr) {
                stk.push(head);
                head = head->left;
            } else {
                head = stk.top(); stk.pop();
                ans.push_back(head->val);
                head = head->right;
            }
        }
    }
    return ans;
}

// 后序遍历，两个栈（LeetCode，函数名建议 postorderTraversal）
vector<int> postorderTraversalTwoStacks(TreeNode* head) {
    vector<int> ans;
    if (head != nullptr) {
        stack<TreeNode*> stk, collect;
        stk.push(head);
        while (!stk.empty()) {
            head = stk.top(); stk.pop();
            collect.push(head);
            if (head->left != nullptr) stk.push(head->left);
            if (head->right != nullptr) stk.push(head->right);
        }
        while (!collect.empty()) {
            ans.push_back(collect.top()->val);
            collect.pop();
        }
    }
    return ans;
}

// 后序遍历，一个栈（LeetCode）
vector<int> postorderTraversalOneStack(TreeNode* h) {
    vector<int> ans;
    if (h != nullptr) {
        stack<TreeNode*> stk;
        stk.push(h);
        TreeNode* lastPrinted = h;//不能置为空，否则无法通过测试样例1这种情况,会短路
        while (!stk.empty()) {
            TreeNode* cur = stk.top();
            if (cur->left != nullptr 
                && lastPrinted != cur->left 
                && lastPrinted != cur->right) {
                stk.push(cur->left);
            } else if (cur->right != nullptr 
                && lastPrinted != cur->right) {
                stk.push(cur->right);
            } else {
                ans.push_back(cur->val);
                lastPrinted = stk.top(); stk.pop();
            }
        }
    }
    return ans;
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);
    preOrder(head);
    cout << endl;
    inOrder(head);
    cout << endl;
    posOrderTwoStacks(head);
    cout << endl;
    posOrderOneStack(head);
    cout << endl;

    // 释放内存（略，因测试简单）
    return 0;
}