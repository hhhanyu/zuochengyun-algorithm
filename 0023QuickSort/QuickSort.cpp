#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int arr[MAXN];
int n;
int first, last;   // 用于改进版 partition 的全局边界

// 交换数组中的两个元素
void swap(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// ------------------------------------------------------------
// 经典划分（不推荐）：<= x 放左边，> x 放右边，返回等于 x 的边界
//xi表示任意一个x的位置
int partition1(int l, int r, int x) {
    int a = l, xi = 0;
    for (int i = l; i <= r; ++i) {
        if (arr[i] <= x) {
            swap(a, i);
            if (arr[a] == x) xi = a;
            ++a;
        }
    }
    swap(xi, a - 1);
    return a - 1;
}

void quickSort1(int l, int r) {
    if (l >= r) return;
    int x = arr[l + rand() % (r - l + 1)];
    int mid = partition1(l, r, x);
    quickSort1(l, mid - 1);
    quickSort1(mid + 1, r);
}

// ------------------------------------------------------------
// 荷兰国旗划分（推荐）：< x 左，== x 中，> x 右，更新全局 first, last
void partition2(int l, int r, int x) {
    first = l;
    last = r;
    int i = l;
    while (i <= last) {
        if (arr[i] == x) {
            ++i;
        } else if (arr[i] < x) {
            swap(first++, i++);
        } else {
            swap(i, last--);
        }
    }
}

void quickSort2(int l, int r) {
    if (l >= r) return;
//rand() 会生成一个很大的随机整数，用它取模（%）区间长度，得到的结果就是 0 到 (长度-1) 之间的随机偏移量。
    int x = arr[l + rand() % (r - l + 1)];
    partition2(l, r, x);
//用临时变量来存，防止递归中全局变量被更改
    int left = first;
    int right = last;
    quickSort2(l, left - 1);
    quickSort2(right + 1, r);
}

// ------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 随机种子，使每次运行随机基准不同
    srand(static_cast<unsigned>(time(nullptr)));

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // 使用改进版的快速排序（荷兰国旗划分），可通过所有测试
    quickSort2(0, n - 1);

    // 输出结果，注意行末无多余空格
    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i] << " ";
    }
    cout << arr[n - 1] << '\n';

    return 0;
}