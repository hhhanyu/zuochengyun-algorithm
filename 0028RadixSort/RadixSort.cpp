#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
const int BASE = 10;

int arr[MAXN];
int help[MAXN];
int cnts[BASE];
int n;

// 返回 number 在 BASE 进制下的位数
int bits(int number) {
    int ans = 0;
    while (number > 0) {
        ans++;
        number /= BASE;
    }
    return ans;
}

// 基数排序核心，bits 为最大值的位数，非负数组
void radixSort(int bits) {
    for (int offset = 1; bits > 0; offset *= BASE, bits--) {
        // 清空计数数组
        fill(cnts, cnts + BASE, 0);
        // 统计当前位的数字出现次数
        // 数字提取某一位的技巧 
        for (int i = 0; i < n; i++) {
            cnts[(arr[i] / offset) % BASE]++;
        }
        // 前缀和，计算每个数字在 help 中的结束位置
        for (int i = 1; i < BASE; i++) {
            cnts[i] += cnts[i - 1];
        }
        // 从后向前稳定排序，保持相对次序
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / offset) % BASE;
            help[--cnts[digit]] = arr[i];
        }
        // 拷贝回原数组
        for (int i = 0; i < n; i++) {
            arr[i] = help[i];
        }
    }
}

// 排序入口，处理负数并调用基数排序
void sort() {
    // 1. 找到最小值，将所有数转为非负
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
    }
    int maxVal = 0;// 记录转化后数组中的最大数，用来告诉基数排序要排几位
    for (int i = 0; i < n; i++) {
        arr[i] -= minVal;
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    // 2. 基数排序
    radixSort(bits(maxVal));
    // 3. 还原数值
    for (int i = 0; i < n; i++) {
        arr[i] += minVal;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort();

    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << arr[n - 1] << '\n';
    return 0;
}