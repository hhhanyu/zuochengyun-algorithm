#include <unordered_map>
#include <vector>
using namespace std;

class FreqStack {
private:
    unordered_map<int, vector<int>> cntValues;   // 频率 -> 该频率下的元素栈（按 push 顺序）
    unordered_map<int, int> valueTimes;          // 值 -> 当前出现次数
    int topTimes;                                // 当前最大频率

public:
    FreqStack() : topTimes(0) {}

    void push(int val) {
        // 更新 val 的出现次数
        int newTimes = ++valueTimes[val];
        // 将 val 加入对应频率的栈中
        cntValues[newTimes].push_back(val);
        // 更新最大频率
        if (newTimes > topTimes) topTimes = newTimes;
    }

    int pop() {
        // 获取最大频率对应的元素列表
        vector<int>& vec = cntValues[topTimes];
        int ans = vec.back();        // 栈顶元素（最近 push 的）
        vec.pop_back();

        // 若该频率下已无元素，则移除该键，并减小最大频率
        if (vec.empty()) {
            cntValues.erase(topTimes);
            --topTimes;
        }

        // 更新 ans 的出现次数
        int times = valueTimes[ans];
        if (times == 1) {
            valueTimes.erase(ans);
        } else {
            valueTimes[ans] = times - 1;
        }
        return ans;
    }
};