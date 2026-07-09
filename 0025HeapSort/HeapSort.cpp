#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int arr[MAXN];
int n;

// 交换两个元素
void swap(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 向上调整（插入建堆）
void heapInsert(int i) {
    while (arr[i] > arr[(i - 1) / 2]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

// 向下调整，size 为当前堆的大小
void heapify(int i, int size) {
    int l = i * 2 + 1;
    while (l < size) {
        //有左孩子，l；有右孩子，l+1
        int best = (l + 1 < size && arr[l + 1] > arr[l]) ? l + 1 : l;
        best = (arr[best] > arr[i]) ? best : i;
        if (best == i) break;
        swap(best, i);
        i = best;
        l = i * 2 + 1;
    }
}

// 方法1：逐个插入建堆 O(n log n)
// 从顶到底建立大根堆，O(n * logn)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
void heapSort1() {
    for (int i = 0; i < n; ++i) {
        heapInsert(i);
    }
    int size = n;
    while (size > 1) {
        swap(0, --size);
        heapify(0, size);
    }
}

// 方法2：从底向上建堆 O(n)
// 从顶到底建立大根堆，O(n * logn)
// 依次弹出堆内最大值并排好序，O(n * logn)
// 整体时间复杂度O(n * logn)
void heapSort2() {
    for (int i = n - 1; i >= 0; --i) {
        heapify(i, n);
    }
    int size = n;
    while (size > 1) {
        swap(0, --size);
        heapify(0, size);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    heapSort2();   // 使用推荐方法，建堆 O(n)

    for (int i = 0; i < n - 1; ++i) {
        cout << arr[i] << ' ';
    }
    cout << arr[n - 1] << '\n';

    return 0;
}