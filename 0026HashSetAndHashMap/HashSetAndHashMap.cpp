#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

// 自定义 Student 类，模拟 Java 中未重写 hashCode/equals 的类
// 在 C++ 中，使用指针作为键来模拟引用比较
class Student {
public:
    int age;
    string name;
    Student(int a, string b) : age(a), name(b) {}
};

int main() {
    // -------- String 示例 --------
    string str1 = "Hello";
    string str2 = "Hello";
    // 输出 true（C++ string 比较内容）
    cout << (str1 == str2 ? "true" : "false") << endl;

    unordered_set<string> set;
    set.insert(str1);
    cout << (set.find("Hello") != set.end() ? "true" : "false") << endl; // true
    cout << (set.find(str2) != set.end() ? "true" : "false") << endl;    // true
    set.insert(str2); // 重复添加，不会增加 size
    cout << set.size() << endl;          // 1
    set.erase(str1);
    set.clear();
    cout << (set.empty() ? "true" : "false") << endl; // true

    cout << "===========" << endl;

    // -------- HashMap<String, String> --------
    unordered_map<string, string> map1;
    map1[str1] = "World";
    cout << (map1.find("Hello") != map1.end() ? "true" : "false") << endl; // true
    cout << (map1.find(str2) != map1.end() ? "true" : "false") << endl;    // true
    auto it = map1.find(str2);//迭代器查找
    if (it != map1.end())
        cout << it->second << endl;  // World
    cout << (map1.find("你好") == map1.end() ? "true" : "false") << endl; // true
    map1.erase("Hello");
    cout << map1.size() << endl;     // 0
    map1.clear();
    cout << (map1.empty() ? "true" : "false") << endl; // true

    cout << "===========" << endl;
    // 哈希表和哈希图的增删查改时间复杂度是大常数级别O(1)
    // 在key的范围固定且可控的情况下，可以用数组替代哈希表结构
    // -------- HashMap<Integer, Integer> 与数组替代 --------
    unordered_map<int, int> map2;
    map2[56] = 7285;
    map2[34] = 3671263;
    map2[17] = 716311;
    map2[24] = 1263161;
    // 数组替代（key 范围可控）
    int arr[100] = {0};
    arr[56] = 7285;
    arr[34] = 3671263;
    arr[17] = 716311;
    arr[24] = 1263161;

    // -------- 自定义类作为键，模拟引用比较 --------
    // 使用指针作为键，比较地址（模拟 Java 引用）
    Student* s1 = new Student(17, "LiHua");
    Student* s2 = new Student(17, "LiHua");
    unordered_map<Student*, string> map3;
    map3[s1] = "This is LiHua";
    cout << (map3.find(s1) != map3.end() ? "true" : "false") << endl; // true
    cout << (map3.find(s2) != map3.end() ? "true" : "false") << endl; // false（不同地址）
    map3[s2] = "This is another LiHua";
    cout << map3.size() << endl;      // 2
    auto it3 = map3.find(s1);
    if (it3 != map3.end())
        cout << it3->second << endl;  // This is LiHua
    auto it4 = map3.find(s2);
    if (it4 != map3.end())
        cout << it4->second << endl;  // This is another LiHua

    // 清理内存
    delete s1;
    delete s2;

    return 0;
}