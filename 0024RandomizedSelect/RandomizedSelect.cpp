#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
//时间复杂度O(n),空间复杂度O(1);
//借用了随机快速选择的划分，即荷兰国旗问题
class Solution {
private:
    int first, last;

    // 荷兰国旗划分，将 <x 放左边，==x 放中间，>x 放右边
    void partition(vector<int>& arr, int l, int r, int x) {
        first = l;
        last = r;
        int i = l;//i是一个指针
        while (i <= last) {
            if (arr[i] == x) {
                ++i;
            } else if (arr[i] < x) {
                swap(arr[first++], arr[i++]);
            } else {
                swap(arr[i], arr[last--]);
            }
        }
    }

    //在无序数组中找到排序后第 i 个位置的元素
    //有些类似二分砍区间，只对一侧进行排序
    int randomizedSelect(vector<int>& arr, int i) {
        int ans = 0;
        int l = 0, r = (int)arr.size() - 1;
        while (l <= r) {
            int x = arr[l + rand() % (r - l + 1)];
            partition(arr, l, r, x);
            if (i < first) {
                r = first - 1;
            } else if (i > last) {
                l = last + 1;
            } else {
                ans = arr[i];
                break;
            }
        }
        return ans;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        // 第 k 大对应于排序后下标 nums.size() - k
        return randomizedSelect(nums, (int)nums.size() - k);
    }
};