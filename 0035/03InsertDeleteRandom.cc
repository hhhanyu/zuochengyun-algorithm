#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> map;   // value -> index in arr
    vector<int> arr;

public:
    RandomizedSet() {
        // 初始化随机种子（可选，以便每次运行不同）
        srand(time(nullptr));
    }

    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }
        map[val] = arr.size();
        arr.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = map.find(val);
        if (it == map.end()) {
            return false;
        }
        int valIndex = it->second;
        int lastVal = arr.back();
        // 将最后一个元素移到待删除位置
        arr[valIndex] = lastVal;
        map[lastVal] = valIndex;
        // 删除原val
        map.erase(it);
        arr.pop_back();
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % arr.size();
        return arr[randomIndex];
    }
};