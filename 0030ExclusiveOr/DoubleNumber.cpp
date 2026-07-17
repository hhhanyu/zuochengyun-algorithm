#include<bits/stdc++.h>
using namespace std;
// 数组中有2种数出现了奇数次，其他的数都出现了偶数次
// 返回这2种出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number-iii/
// 如下代码是C++版，直接提交可以通过，注意看代码中的注释

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int eor1 = 0;
        for (int x : nums) {
            eor1 ^= x;
        }
        // eor1 : a ^ b
		// Brian Kernighan算法
		// 提取出二进制里最右侧的1
        // 为什么这么写？自己去查！语言问题自己搞定
        // 在 C++ 中，负数的右移行为是实现定义（implementation-defined） 的，并且负数的左移行为甚至是未定义（undefined） 的。为了写出在任何编译器上都能正确运行的可移植（portable） 代码，C++ 程序员必须通过 unsigned int 转换来“强制”获得一个确定的、无符号的位模式，从而避免依赖特定编译器的实现细节
        unsigned int rightOne = (unsigned int)eor1 & (-(unsigned int)eor1);
        // 利用最右侧的1把所有数字划分为对立的两个部分，a和b必分属这两部分，然后分别异或最后只会剩下出现奇数次的a和b
        int a = 0;
        for (int x : nums) {
            if (((unsigned int)x & rightOne) == 0) {
                a ^= x;
            }
        }
        return {a, eor1 ^ a};
    }
};