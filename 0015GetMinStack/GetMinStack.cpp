#include <stack>
#include <algorithm>

// ========== 版本1：双栈实现 ==========
// 对应 Java 的 MinStack1
class MinStack1 {
private:
    std::stack<int> data;   // 数据栈
    std::stack<int> min;    // 辅助栈，存每一步的最小值

public:
    MinStack1() {}

    void push(int val) {
        data.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        } else {
            min.push(min.top());   // 重复当前最小值
        }
    }

    void pop() {
        data.pop();
        min.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};


// ========== 版本2：数组实现 ==========
// 对应 Java 的 MinStack2
class MinStack2 {
private:
    static const int MAXN = 8001;
    int data[MAXN];   // 数据数组
    int minArr[MAXN]; // 最小值数组
    int size;         // 当前栈大小

public:
    MinStack2() : size(0) {}

    void push(int val) {
        data[size] = val;
        if (size == 0 || val <= minArr[size - 1]) {
            minArr[size] = val;
        } else {
            minArr[size] = minArr[size - 1];
        }
        size++;
    }

    void pop() {
        size--;
    }

    int top() {
        return data[size - 1];
    }

    int getMin() {
        return minArr[size - 1];
    }
};