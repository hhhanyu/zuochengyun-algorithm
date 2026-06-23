#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100001;
int arr[MAXN];
int help[MAXN];
int n;

// 合并两个有序区间 [l...m] 和 [m+1...r]
void merge(int l, int m, int r) {
    int i = l;
    int a = l;
    int b = m + 1;
    while (a <= m && b <= r) {//左右两侧没耗尽就继续
        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];//谁小拷贝谁到辅助数组;i++,先返回当前值，再自增1，先给i位置填上数，再更新 
    }
    //出循环，必有一侧指针已越界，而另一侧不越界
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }//help数组已排好序，抄回原数组即可
    for (i = l; i <= r; i++) {//注意从l开始，否则会超时；如果错把 i 从 0 开始，时间复杂度会从标准的 O(n log n) 退化为 O(n^2)
        arr[i] = help[i];
    }
}

// 归并排序递归版
void mergeSort1(int l, int r) {
    if (l == r) return;//basecase
    int m = (l + r) / 2;//求中点
    mergeSort1(l, m);
    mergeSort1(m + 1, r);
    merge(l, m, r);
}

// 归并排序非递归版
void mergeSort2() {
    for (int l, m, r, step = 1; step < n; step <<= 1) {//step每次翻倍
        l = 0;
        while (l < n) {
            m = l + step - 1;
            if (m + 1 >= n) break;
            r = min(l + (step << 1) - 1, n - 1);
            merge(l, m, r);
            l = r + 1;
        }
    }
}

int main() {
    // 取消 cin/cout 与 C 标准 IO 的同步，提升 IO 效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // mergeSort1(0, n - 1);
    mergeSort2();

    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << '\n';

    return 0;
}