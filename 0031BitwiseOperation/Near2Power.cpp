#include <climits>

class Solution {
public:
    int near2power(int n) {
        if (n <= 0) return 1;
        unsigned int x = static_cast<unsigned int>(n) - 1;  // 转为无符号，避免溢出
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        // 如果 x+1 大于 INT_MAX，则结果会回绕，变为 INT_MIN，符合要求
        return static_cast<int>(x + 1);
    }
};