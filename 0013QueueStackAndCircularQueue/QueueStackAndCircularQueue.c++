#include <vector>
#include <queue>
#include <stack>
#include <stdexcept>

// 使用 STL queue 的封装（对应 Java 的 Queue1）
class Queue1 {
private:
    std::queue<int> q;
public:
    bool isEmpty() const { return q.empty(); }
    void offer(int num) { q.push(num); }
    int poll() {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        int front = q.front();
        return front;
    }
    int peek() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return q.front();
    }
    int size() const { return q.size(); }
};

// 基于数组的队列（对应 Java 的 Queue2）
class Queue2 {
private:
    std::vector<int> queue;
    int l, r;
public:
    // n 表示加入操作的总次数上限
    Queue2(int n) : queue(n), l(0), r(0) {}
    bool isEmpty() const { return l == r; }
    void offer(int num) { queue[r++] = num; }
    int poll() {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return queue[l++];
    }
    int head() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return queue[l];
    }
    int tail() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return queue[r - 1];
    }
    int size() const { return r - l; }
};

// 使用 STL stack 的封装（对应 Java 的 Stack1）
class Stack1 {
private:
    std::stack<int> st;
public:
    bool isEmpty() const { return st.empty(); }
    void push(int num) { st.push(num); }
    int pop() {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        int top = st.top();
        return top;
    }
    int peek() const {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        return st.top();
    }
    int size() const { return st.size(); }
};

// 基于数组的栈（对应 Java 的 Stack2）
class Stack2 {
private:
    std::vector<int> stack;
    int size;
public:
    // n 表示同时在栈中的元素个数上限
    Stack2(int n) : stack(n), size(0) {}
    bool isEmpty() const { return size == 0; }
    void push(int num) { stack[size++] = num; }
    int pop() {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        return stack[--size];
    }
    int peek() const {
        if (isEmpty()) throw std::runtime_error("Stack is empty");
        return stack[size - 1];
    }
    int size() const { return size; }
};

// 循环队列（对应 Java 的 MyCircularQueue）
class MyCircularQueue {
private:
    std::vector<int> queue;
    int l, r, size, limit;
//l代表头部，r代表尾部
public:
    MyCircularQueue(int k) : queue(k), l(0), r(0), size(0), limit(k) {}
//如果队列满了，什么也不做，返回false
//如果队列没满，将value加入队列，返回true
    bool enQueue(int value) {
        if (isFull()) return false;
        queue[r] = value;
        r = r == limit - 1 ? 0 : (r + 1);//如果r已经到limit - 1位置，则回退到0处以免越界；这同时表示这个队列接下来只能执行出队操作
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        l = l == limit - 1 ? 0 : (l + 1);
        size--;
        return true;
    }

    int Front() const {
        if (isEmpty()) return -1;
        return queue[l];
    }

    int Rear() const {
        if (isEmpty()) return -1;
        int last = (r == 0) ? (limit - 1) : (r - 1);
        return queue[last];
    }

    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == limit; }
};