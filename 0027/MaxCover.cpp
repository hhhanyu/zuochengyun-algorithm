#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
int n;
int line[MAXN][2]; // 存储每条线段的起点和终点，0为起点，1为终点

// 最大线段重合数（左闭右闭）
int compute() {
    // 按起点升序排序
    sort(line, line + n, [](int a[], int b[]) {
        return a[0] < b[0];
    });
    // 小根堆，存储当前活跃线段的终点
    priority_queue<int, vector<int>, greater<int>> heap;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // 弹出所有终点 <= 当前起点的线段（因为左闭右闭，等于时没有重合）
        while (!heap.empty() && heap.top() <= line[i][0]) {
            heap.pop();
        }
        heap.push(line[i][1]);
        ans = max(ans, (int)heap.size());
    }
    return ans;
}

// LeetCode 253. 会议室 II（左闭右开？但原题是区间重叠，使用 <= 判断，与牛客一致）
int minMeetingRooms(vector<vector<int>>& meeting) {
    int n = meeting.size();
    sort(meeting.begin(), meeting.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    priority_queue<int, vector<int>, greater<int>> heap;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!heap.empty() && heap.top() <= meeting[i][0]) {
            heap.pop();
        }
        heap.push(meeting[i][1]);
        ans = max(ans, (int)heap.size());
    }
    return ans;
}

// LeetCode 2406. 划分区间为最少组数（左闭右开，重叠条件为严格小于）
int minGroups(vector<vector<int>>& meeting) {
    int n = meeting.size();
    sort(meeting.begin(), meeting.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    priority_queue<int, vector<int>, greater<int>> heap;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        // 注意：此处为 <，因为原题意认为 [1,4] 和 [4,5] 有重叠（4 点重合）
        while (!heap.empty() && heap.top() < meeting[i][0]) {
            heap.pop();
        }
        heap.push(meeting[i][1]);
        ans = max(ans, (int)heap.size());
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读取多组数据，每组第一行为 n
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> line[i][0] >> line[i][1];
        }
        cout << compute() << '\n';
    }
    return 0;
}