#include <deque>
#include <vector>

// ========== 版本1：基于 std::deque ==========
// 提交时把类名改成 MyCircularDeque
class MyCircularDeque1 {
private:
    std::deque<int> deque;
    int size;
    int limit;

public:
    MyCircularDeque1(int k) : size(0), limit(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        deque.push_front(value);
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        deque.push_back(value);
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        deque.pop_front();
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        deque.pop_back();
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque.front();
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deque.back();
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};

// ========== 版本2：基于数组（推荐） ==========
// 提交时把类名改成 MyCircularDeque
class MyCircularDeque2 {
private:
    std::vector<int> deque;
    int l, r, size, limit;

public:
    MyCircularDeque2(int k) : deque(k), l(0), r(0), size(0), limit(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            l = r = 0;
            deque[0] = value;
        } else {
            l = (l == 0) ? (limit - 1) : (l - 1);
            deque[l] = value;
        }
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            l = r = 0;
            deque[0] = value;
        } else {
            r = (r == limit - 1) ? 0 : (r + 1);
            deque[r] = value;
        }
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        l = (l == limit - 1) ? 0 : (l + 1);
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        r = (r == 0) ? (limit - 1) : (r - 1);
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque[l];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deque[r];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == limit;
    }
};