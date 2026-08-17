#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> mp;   // key -> (value, timestamp)
int setAllValue = 0;
int setAllTime = -1;
int cnt = 0;                             // 全局时间戳计数器

void put(int k, int v) {
    auto it = mp.find(k);
    if (it != mp.end()) {
        it->second.first = v;
        it->second.second = cnt++;
    } else {
        mp.emplace(k, make_pair(v, cnt++));
    }
}

void setAll(int v) {
    setAllValue = v;
    setAllTime = cnt++;
}

int get(int k) {
    auto it = mp.find(k);
    if (it == mp.end()) return -1;
    // 若该键的时间戳大于 setAll 的时间戳，说明是在 setAll 之后更新的，返回实际值
    if (it->second.second > setAllTime) {
        return it->second.first;
    } else {
        return setAllValue;
    }
}

int main() {
    int n, op, a, b;
    while (scanf("%d", &n) != EOF) {
        mp.clear();
        setAllValue = 0;
        setAllTime = -1;
        cnt = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d", &a, &b);
                put(a, b);
            } else if (op == 2) {
                scanf("%d", &a);
                printf("%d\n", get(a));
            } else { // op == 3
                scanf("%d", &a);
                setAll(a);
            }
        }
    }
    return 0;
}