#include <iostream>
using namespace std;

// 当 i != j 时，异或交换可以完成交换功能
// 当 i == j 时，异或交换会出错（将值变为0）
// 因此这种写法仅作了解，并不推荐在生产代码中使用
void swap(int arr[], int i, int j) {
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

int main() {
    // 利用性质 n ^ 0 = n,n ^ n = 0
    int a = -2323;
    int b = 10;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << a << endl;
    cout << b << endl;

    int arr[] = { 3, 5 };
    swap(arr, 0, 1);
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    swap(arr, 0, 0);  // 此时 i == j，交换会导致 arr[0] 变为 0
    cout << arr[0] << endl;

    return 0;
}