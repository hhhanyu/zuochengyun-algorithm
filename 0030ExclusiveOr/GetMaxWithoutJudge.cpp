#include <iostream>
#include <climits>
using namespace std;

// 翻转 0 和 1（必须保证输入是 0 或 1）
int flip(int n) {
    return n ^ 1;
}

// 非负数返回 1，负数返回 0
int sign(int n) {
    // 使用无符号右移获取符号位（相当于 Java 的 >>> 31）
    return flip(static_cast<unsigned int>(n) >> 31);
}

// 有溢出风险的实现
int getMax1(int a, int b) {
    int c = a - b;                // 可能溢出
    int returnA = sign(c);        // c >= 0 时为 1，c < 0 时为 0
    int returnB = flip(returnA);  // 取反
    return a * returnA + b * returnB;
}

// 无溢出风险的实现
int getMax2(int a, int b) {
    int c = a - b;                // 同号相减不会溢出，但此处用于计算 sc，需注意溢出可能影响 sc，但下方逻辑已规避
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    int diffAB = sa ^ sb;         // a 和 b 符号不同则为 1，相同则为 0
    int sameAB = flip(diffAB);    // 符号相同则为 1
    // 当符号不同时，returnA 取 a 的符号；符号相同时，returnA 取 c 的符号
    int returnA = diffAB * sa + sameAB * sc;
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}

int main() {
    int a = INT_MIN;
    int b = INT_MAX;

    // getMax1 会因为溢出导致错误结果
    cout << getMax1(a, b) << endl; // 输出错误值（例如 -1）
    // getMax2 永远正确
    cout << getMax2(a, b) << endl; // 输出 INT_MAX

    return 0;
}