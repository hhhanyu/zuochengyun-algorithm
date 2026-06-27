#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int n;

int arr[MAXN];
int help[MAXN];

int merge(int l, int m, int r) {
    int ans = 0;
    for (int i = l,j = m + 1;i <= m;i++) {
        while (j <= r && (long) arr[i] > (long) arr[j] * 2) {
            j ++;
        }
        ans += j - m - 1;
    }
    int i = l, a = l, b = m + 1;
    while (a <= m && b <= r) {
        help[i++] = (arr[a] <= arr[b] ? arr[a++] : arr[b++]);
    }
    while (a <= m) {
        help[i++] = arr[a++];
    }
    while (b <= r) {
        help[i++] = arr[b++];
    }
    for (i = l; i <= r; i++) {
        arr[i] = help[i];
    }
    return ans;
}

int consts(int l, int r) {
    if (l == r) {
        return 0;
    }
    int m = (l + r) >> 1;
    return consts(l, m) + consts(m + 1, r) + merge(l, m, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << consts(0, n - 1) << '\n';
    }
    return 0;
}