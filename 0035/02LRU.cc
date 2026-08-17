#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct DoubleNode {
        int key, val;
        DoubleNode *last, *next;
        DoubleNode(int k, int v) : key(k), val(v), last(nullptr), next(nullptr) {}
    };

    struct DoubleList {
        DoubleNode *head, *tail;
        DoubleList() : head(nullptr), tail(nullptr) {}

        void addNode(DoubleNode* newNode) {
            if (!newNode) return;
            if (!head) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->last = tail;
                tail = newNode;
            }
        }

        void moveNodeToTail(DoubleNode* node) {
            if (tail == node) return;
            if (head == node) {
                head = node->next;
                head->last = nullptr;
            } else {
                node->last->next = node->next;
                node->next->last = node->last;
            }
            node->last = tail;
            node->next = nullptr;
            tail->next = node;
            tail = node;
        }

        DoubleNode* removeHead() {
            if (!head) return nullptr;
            DoubleNode* ans = head;
            if (head == tail) {
                head = tail = nullptr;
            } else {
                head = ans->next;
                ans->next = nullptr;
                head->last = nullptr;
            }
            return ans;
        }
    };

    unordered_map<int, DoubleNode*> keyNodeMap;
    DoubleList nodeList;
    int capacity;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = keyNodeMap.find(key);
        if (it == keyNodeMap.end()) return -1;
        DoubleNode* node = it->second;
        nodeList.moveNodeToTail(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = keyNodeMap.find(key);
        if (it != keyNodeMap.end()) {
            DoubleNode* node = it->second;
            node->val = value;
            nodeList.moveNodeToTail(node);
        } else {
            if (keyNodeMap.size() == capacity) {
                DoubleNode* removed = nodeList.removeHead();
                keyNodeMap.erase(removed->key);
                delete removed;          // 防止内存泄漏
            }
            DoubleNode* newNode = new DoubleNode(key, value);
            keyNodeMap[key] = newNode;
            nodeList.addNode(newNode);
        }
    }
};