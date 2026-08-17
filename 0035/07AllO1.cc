#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
using namespace std;

class AllOne {
private:
    struct Bucket {
        unordered_set<string> set;
        int cnt;
        Bucket *last, *next;
        Bucket(const string& s, int c) : cnt(c), last(nullptr), next(nullptr) {
            set.insert(s);
        }
        Bucket(int c) : cnt(c), last(nullptr), next(nullptr) {}  // dummy 节点专用
    };

    Bucket* head;      // 哨兵，cnt = 0
    Bucket* tail;      // 哨兵，cnt = INT_MAX
    unordered_map<string, Bucket*> map;   // key -> 所在桶

    // 在 cur 后面插入 pos
    void insertAfter(Bucket* cur, Bucket* pos) {
        pos->next = cur->next;
        cur->next->last = pos;
        cur->next = pos;
        pos->last = cur;
    }

    // 删除节点并释放内存
    void removeBucket(Bucket* cur) {
        cur->last->next = cur->next;
        cur->next->last = cur->last;
        delete cur;
    }

public:
    AllOne() {
        head = new Bucket(0);
        tail = new Bucket(INT_MAX);
        head->next = tail;
        tail->last = head;
    }

    ~AllOne() {
        Bucket* cur = head;
        while (cur) {
            Bucket* next = cur->next;
            delete cur;
            cur = next;
        }
    }

    void inc(string key) {
        auto it = map.find(key);
        if (it == map.end()) {
            // key 不存在
            if (head->next->cnt == 1) {
                map[key] = head->next;
                head->next->set.insert(key);
            } else {
                Bucket* newBucket = new Bucket(key, 1);
                map[key] = newBucket;
                insertAfter(head, newBucket);
            }
        } else {
            Bucket* bucket = it->second;
            // 检查下一个桶是否正好是 cnt+1
            if (bucket->next->cnt == bucket->cnt + 1) {
                map[key] = bucket->next;
                bucket->next->set.insert(key);
            } else {
                Bucket* newBucket = new Bucket(key, bucket->cnt + 1);
                map[key] = newBucket;
                insertAfter(bucket, newBucket);
            }
            // 从原桶移除 key
            bucket->set.erase(key);
            if (bucket->set.empty()) {
                removeBucket(bucket);
            }
        }
    }

    void dec(string key) {
        auto it = map.find(key);
        if (it == map.end()) return;  // 题目保证不会出现无效调用

        Bucket* bucket = it->second;
        if (bucket->cnt == 1) {
            map.erase(key);
        } else {
            // 检查前一个桶是否正好是 cnt-1
            if (bucket->last->cnt == bucket->cnt - 1) {
                map[key] = bucket->last;
                bucket->last->set.insert(key);
            } else {
                Bucket* newBucket = new Bucket(key, bucket->cnt - 1);
                map[key] = newBucket;
                insertAfter(bucket->last, newBucket);
            }
        }
        // 从原桶移除 key
        bucket->set.erase(key);
        if (bucket->set.empty()) {
            removeBucket(bucket);
        }
    }

    string getMaxKey() {
        if (tail->last == head) return "";
        return *(tail->last->set.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->set.begin());
    }
};