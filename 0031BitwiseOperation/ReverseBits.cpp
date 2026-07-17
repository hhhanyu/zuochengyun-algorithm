#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // 交换相邻位
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        // 交换每两位一组
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        // 交换每四位一组
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        // 交换每八位一组
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        // 交换高16位和低16位
        n = (n >> 16) | (n << 16);
        return n;
    }
};