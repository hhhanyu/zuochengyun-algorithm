#include <stack>
#include <queue>

// 用栈实现队列
class MyQueue {
private:
    std::stack<int> in;
    std::stack<int> out;
    // 倒数据
	// 从in栈，把数据倒入out栈
	// 1) out空了，才能倒数据
	// 2) 如果倒数据，in必须倒完
    void inToOut() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        in.push(x);
        inToOut();
    }

    int pop() {
        inToOut();
        int val = out.top();
        out.pop();
        return val;
    }

    int peek() {
        inToOut();
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

// 用队列实现栈
class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};