#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std;

// 位图的实现
// Bitset(int size)
// void add(int num)
// void remove(int num)
// void reverse(int num)
// bool contains(int num)
class Bitset {
public:
    vector<int> set;

    // n个数字 : 0~n-1
    Bitset(int n) {
        // a/b如果结果想向上取整，可以写成 : (a+b-1)/b
        // 前提是a和b都是非负数
        set.assign((n + 31) / 32, 0);
    }

    void add(int num) {
        set[num / 32] |= 1U << (num % 32);// 1 是有符号 32 位 int。C++ 规定：移位次数不能小于 0，也不能大于等于变量总比特数，否则属于未定义行为。在当前代码中 num 范围是 [0,n-1]，num%32结果落在 0~31，移位次数合法，不会出现移位≥32 的问题。但是 1 << 31 会把 1 移到有符号 int 的符号位，造成有符号整数溢出，依然属于未定义行为。规范写法应当使用无符号字面量 1U << k，消除符号位溢出风险。
    }

    void remove(int num) {
        set[num / 32] &= ~(1U << (num % 32));
    }

    void reverse(int num) {
        set[num / 32] ^= 1U << (num % 32);
    }

    bool contains(int num) {
        return ((set[num / 32] >> (num % 32)) & 1U) == 1;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // 初始化随机种子

    int n = 1000;
    int testTimes = 10000;
    cout << "测试开始" << endl;

    // 实现的位图结构
    Bitset bitSet(n);
    // 直接用 unordered_set 做对比测试
    unordered_set<int> hashSet;

    cout << "调用阶段开始" << endl;
    for (int i = 0; i < testTimes; i++) {
        double decide = rand() / (RAND_MAX + 1.0); // 0~1 之间均匀分布
        // number -> 0 ~ n-1，等概率得到
        int number = static_cast<int>(rand() / (RAND_MAX + 1.0) * n);

        if (decide < 0.333) {
            bitSet.add(number);
            hashSet.insert(number);
        } else if (decide < 0.666) {
            bitSet.remove(number);
            hashSet.erase(number);
        } else {
            bitSet.reverse(number);
            auto it = hashSet.find(number);
            if (it != hashSet.end()) {
                hashSet.erase(it);
            } else {
                hashSet.insert(number);
            }
        }
    }
    cout << "调用阶段结束" << endl;

    cout << "验证阶段开始" << endl;
    for (int i = 0; i < n; i++) {
        if (bitSet.contains(i) != (hashSet.find(i) != hashSet.end())) {
            cout << "出错了!" << endl;
        }
    }
    cout << "验证阶段结束" << endl;
    cout << "测试结束" << endl;

    return 0;
}