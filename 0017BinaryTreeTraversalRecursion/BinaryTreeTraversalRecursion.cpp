#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 递归基本样子，用来理解递归序
void f(TreeNode* head) {
    if (head == nullptr) return;
    // 1
    f(head->left);
    // 2
    f(head->right);
    // 3
}

// 先序打印所有节点，递归版
void preOrder(TreeNode* head) {
    if (head == nullptr) return;
    cout << head->val << " ";
    preOrder(head->left);
    preOrder(head->right);
}

// 中序打印所有节点，递归版
void inOrder(TreeNode* head) {
    if (head == nullptr) return;
    inOrder(head->left);
    cout << head->val << " ";
    inOrder(head->right);
}

// 后序打印所有节点，递归版
void posOrder(TreeNode* head) {
    if (head == nullptr) return;
    posOrder(head->left);
    posOrder(head->right);
    cout << head->val << " ";
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
    cout << endl;

    inOrder(head);
    cout << endl;
    cout << endl;

    posOrder(head);
    cout << endl;
    cout << endl;

    // 释放内存（略，简单测试可忽略）

    return 0;
}