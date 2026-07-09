#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    // ------------------ TreeMap (std::map) ------------------
    map<int, string> treeMap;
    treeMap[5] = "This is 5";
    treeMap[7] = "This is 7";
    treeMap[1] = "This is 1";
    treeMap[2] = "This is 2";
    treeMap[3] = "This is 3";
    treeMap[4] = "This is 4";
    treeMap[8] = "This is 8";

    // containsKey
    cout << (treeMap.find(1) != treeMap.end() ? "true" : "false") << endl;
    cout << (treeMap.find(10) != treeMap.end() ? "true" : "false") << endl;

    // get
    auto it = treeMap.find(4);
    if (it != treeMap.end())
        cout << it->second << endl;   // This is 4
    treeMap[4] = "LiHua is 4";            // put(4, "LiHua is 4")
    it = treeMap.find(4);
    if (it != treeMap.end())
        cout << it->second << endl;   // LiHua is 4
 
    // remove
    treeMap.erase(4);
    it = treeMap.find(4);
    cout << (it == treeMap.end() ? "true" : "false") << endl;  // true (null)

    // firstKey / lastKey
    cout << treeMap.begin()->first << endl;   // 1
    cout << treeMap.rbegin()->first << endl;  // 8

    // floorKey(4) : <=4 的最大键
    auto itFloor = treeMap.upper_bound(4);    // 第一个 >4 的迭代器
    if (itFloor != treeMap.begin()) {
        --itFloor;
        cout << itFloor->first << endl;       // 输出3
    } else {
        cout << "null" << endl;
    }

    // ceilingKey(4) : >=4 的最小键
    auto itCeil = treeMap.lower_bound(4);     // 第一个 >=4 的迭代器
    if (itCeil != treeMap.end()) {
        cout << itCeil->first << endl;        // 输出5
    } else {
        cout << "null" << endl;
    }

    cout << "========" << endl;

    // ------------------ TreeSet (std::set) ------------------
    set<int> set;
    set.insert(3);
    set.insert(3);
    set.insert(4);
    set.insert(4);
    cout << "The size of the set : " << set.size() << endl;  // 2
    while (!set.empty()) {
        // pollFirst() -> 取出最小并删除
        auto itSet = set.begin();
        cout << *itSet << endl;
        set.erase(itSet);
        // 若要 pollLast()，则使用 rbegin() 并删除
    }

    // ------------------ PriorityQueue (std::priority_queue) ------------------
    // C++ 默认大根堆，需使用 greater<int> 实现小根堆
    priority_queue<int, vector<int>, greater<int>> heap1;   // 小根堆
    heap1.push(3);
    heap1.push(3);
    heap1.push(4);
    heap1.push(4);
    cout << "堆大小 : " << heap1.size() << endl;
    while (!heap1.empty()) {
        cout << heap1.top() << endl;
        heap1.pop();
    }

    // 大根堆：C++ 默认的就是大根堆（less）
    priority_queue<int> heap2;   // 大根堆
    heap2.push(3);
    heap2.push(3);
    heap2.push(4);
    heap2.push(4);
    cout << "堆大小 : " << heap2.size() << endl;
    while (!heap2.empty()) {
        cout << heap2.top() << endl;
        heap2.pop();
    }

    return 0;
}