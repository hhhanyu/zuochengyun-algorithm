#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return find(nums, 3);
    }

    // 更通用的方法
    // 已知数组中只有1种数出现次数少于m次，其他数都出现了m次
    // 返回出现次数小于m次的那种数
    int find(vector<int>& arr, int m) {
        int cnts[32] = {0};  // 统计每一位上 1 出现的次数
        for (int num : arr) {
            for (int i = 0; i < 32; i++) {
                cnts[i] += (num >> i) & 1;  // 提取第 i 位的值（0 或 1）,逐位计次
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (cnts[i] % m != 0) {          // 如果该位上的 1 的个数不是 m 的倍数
                ans |= (1 << i);             // 说明目标数在该位上是 1
            }
        }
        return ans;
    }
};