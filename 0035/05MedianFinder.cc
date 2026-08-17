#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap;                       // 大根堆，存较小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小根堆，存较大的一半

    void balance() {
        if (maxHeap.size() - minHeap.size() == 2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() - maxHeap.size() == 2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balance();
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
        }
    }
};