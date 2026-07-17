#include <cstdint>

class Solution {
public:
    int hammingDistance(int x, int y) {
        return cntOnes(x ^ y);
    }

    int cntOnes(int n) {
        // 转为无符号，确保右移为逻辑右移
        uint32_t x = static_cast<uint32_t>(n);
        // 分治法统计二进制中 1 的位数
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
        x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
        x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
        return static_cast<int>(x);
    }
};