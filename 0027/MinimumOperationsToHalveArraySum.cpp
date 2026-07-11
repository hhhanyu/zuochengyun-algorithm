#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        // 1. 构建大根堆 (默认就是大根堆)
        priority_queue<double> maxHeap;
        double totalSum = 0.0;
        for (int num : nums) {
            maxHeap.push((double)num);
            totalSum += num;
        }

        double target = totalSum / 2.0; // 需要减少到的目标值
        int operations = 0;
        double reducedSum = 0.0; // 已经减少的总和

        // 2. 循环直到减少的总和达到目标
        while (reducedSum < target) {
            double largest = maxHeap.top();
            maxHeap.pop();

            double half = largest / 2.0;
            reducedSum += half;   // 本次操作减少的量
            operations++;

            maxHeap.push(half);   // 将减半后的数放回堆中
        }

        return operations;
    }


    private:
    vector<long long> heap;
    int heapSize;

    // 堆化 (大根堆)
    void heapify(int i) {
        int left = i * 2 + 1;
        while (left < heapSize) {
            // 找出左右孩子中较大的一个
            int largest = left;
            if (left + 1 < heapSize && heap[left + 1] > heap[left]) {
                largest = left + 1;
            }
            // 如果孩子节点比父节点大，则交换
            if (heap[largest] > heap[i]) {
                swap(heap[largest], heap[i]);
                i = largest;
                left = i * 2 + 1;
            } else {
                break;
            }
        }
    }

public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        heap.resize(n);
        heapSize = n;
        long long totalSum = 0;

        // 1. 初始化堆，同时将每个数左移20位 (相当于乘以 2^20) ，防止double精度不够用出问题
        for (int i = 0; i < n; ++i) {
            heap[i] = (long long)nums[i] << 20; 
            totalSum += heap[i];
        }

        // 2. 从最后一个非叶子节点开始，自底向上构建堆
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(i);
        }

        long long target = totalSum / 2;
        int operations = 0;
        long long reducedSum = 0;

        // 3. 循环操作
        while (reducedSum < target) {
            heap[0] /= 2;          // 将堆顶（最大值）减半
            reducedSum += heap[0]; // 累加减少的量
            operations++;
            heapify(0);            // 调整堆，使其重新成为大根堆
        }

        return operations;
    }

};