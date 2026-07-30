#include <climits>

class Solution {
public:
    // 只提交 Solution 类中的 divide 方法即可，其他辅助方法可放在类内

    static int divide(int a, int b) {
        const int MIN = INT_MIN;  // 整数最小值

        if (a == MIN && b == MIN) {
            // a 和 b 都是整数最小
            return 1;
        }
        if (a != MIN && b != MIN) {
            // a 和 b 都不是整数最小，正常相除
            return div(a, b);
        }
        if (b == MIN) {
            // a 不是整数最小，b 是整数最小
            return 0;
        }
        // a 是整数最小，b 是 -1，返回整数最大（题目明确要求）
        if (b == neg(1)) {
            return INT_MAX;
        }
        // a 是整数最小，b 不是整数最小，b 也不是 -1
        a = add(a, b > 0 ? b : neg(b));
        int ans = div(a, b);
        int offset = b > 0 ? neg(1) : 1;
        return add(ans, offset);
    }

private:
    // 必须保证 a 和 b 都不是整数最小值，返回 a 除以 b 的结果
    static int div(int a, int b) {
        int x = a < 0 ? neg(a) : a;
        int y = b < 0 ? neg(b) : b;
        int ans = 0;
        for (int i = 30; i >= 0; i = minus(i, 1)) {
            if ((x >> i) >= y) {
                ans |= (1 << i);
                x = minus(x, y << i);
            }
        }
        return (a < 0) != (b < 0) ? neg(ans) : ans;
    }

    static int add(int a, int b) {
        int ans = a;
        while (b != 0) {
            // ans : a 和 b 无进位相加的结果
            ans = a ^ b;
            // b  : a 和 b 相加时的进位信息
            b = (a & b) << 1;
            a = ans;
        }
        return ans;
    }

    static int minus(int a, int b) {
        return add(a, neg(b));
    }

    static int neg(int n) {
        return add(~n, 1);
    }

public:
    // 龟速乘（取模版），后续课程有用，此处保留但不影响提交
    static long long multiply(long long a, long long b, long long mod) {
        a = (a % mod + mod) % mod;
        b = (b % mod + mod) % mod;
        long long ans = 0;
        while (b != 0) {
            if ((b & 1) != 0) {
                ans = (ans + a) % mod;
            }
            a = (a + a) % mod;
            b >>= 1;
        }
        return ans;
    }
};