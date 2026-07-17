#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int eorAll = 0, eorHas = 0;
        int n = nums.size();
        
        // 遍历数组，eorAll 异或 0 到 n-1，eorHas 异或 nums 中的所有元素
        for (int i = 0; i < n; i++) {
            eorAll ^= i;
            eorHas ^= nums[i];
        }
        // 将 n 也异或到 eorAll 中，完成 0 到 n 的完整范围
        eorAll ^= n;
        
        // 最终的异或结果就是缺失的数字
        return eorAll ^ eorHas;
    }
};