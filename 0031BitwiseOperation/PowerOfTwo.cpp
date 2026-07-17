class Solution {
public:
// BK算法，提取出最右位的1，2的幂的二进制表示一定只有这一位1
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & -n) == n;
    }
};