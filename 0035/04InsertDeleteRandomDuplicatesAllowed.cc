#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> map;   // value -> set of indices in arr
    vector<int> arr;

public:
    RandomizedCollection() {
        srand(time(nullptr));   // 可选，使随机序列不同
    }

    bool insert(int val) {
        arr.push_back(val);
        // 获取或创建该值对应的索引集合
        auto& idxSet = map[val];
        idxSet.insert(arr.size() - 1);
        // 若插入后集合大小仅为1，说明此前该值不存在
        return idxSet.size() == 1;
    }

    bool remove(int val) {
        auto it = map.find(val);
        if (it == map.end()) return false;

        unordered_set<int>& valSet = it->second;
        // 取出 val 的任意一个索引
        int valAnyIndex = *valSet.begin();
        int lastVal = arr.back();

        if (val == lastVal) {
            // 直接删除最后一个索引
            valSet.erase(arr.size() - 1);
        } else {
            // 将最后一个元素移到 valAnyIndex 位置
            unordered_set<int>& lastSet = map[lastVal];
            lastSet.insert(valAnyIndex);          // 新位置加入 lastVal 的集合
            arr[valAnyIndex] = lastVal;           // 覆盖数组
            lastSet.erase(arr.size() - 1);        // 移除原末尾索引（即将被删除）
            valSet.erase(valAnyIndex);            // 移除 val 的旧索引
        }

        arr.pop_back();  // 删除末尾元素

        if (valSet.empty()) {
            map.erase(val);  // 若 val 已无任何索引，移除该键
        }
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % arr.size();
        return arr[randomIndex];
    }
};