class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 当 left 小于 right 时，不断消去 right 最右侧的 1
        while (left < right) {
            right -= right & -right;
        }
        return right;
    }
};