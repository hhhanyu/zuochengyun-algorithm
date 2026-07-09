#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

// 员工类，增加 id 以便区分相同 company & age 的对象
class Employee {
public:
    int company;
    int age;
    int id;  // 唯一标识，用于避免 set 去重 

    static int nextId;  // 静态计数器

    Employee(int c, int a) : company(c), age(a), id(nextId++) {}

    // 用于打印
    void print() const {
        cout << company << " , " << age;
    }
};
int Employee::nextId = 0;

// 比较器：按年龄升序
struct EmployeeComparatorByAge {
    bool operator()(const Employee& a, const Employee& b) const {
        return a.age < b.age;  // 年龄小者优先级高（等价于 Java 返回负数）
    }
};

int main() {
    // 创建员工对象
    Employee s1(2, 27);
    Employee s2(1, 60);
    Employee s3(4, 19);
    Employee s4(3, 23);
    Employee s5(1, 35);
    Employee s6(3, 55);
    vector<Employee> arr = {s1, s2, s3, s4, s5, s6};

    // 1. 按年龄升序排序（使用 Comparator 类）
    sort(arr.begin(), arr.end(), EmployeeComparatorByAge());
    for (const auto& e : arr) {
        e.print();
        cout << endl;
    }

    cout << "=====" << endl;

    // 2. 按年龄降序（使用 Lambda 表达式）
    sort(arr.begin(), arr.end(), [](const Employee& a, const Employee& b) {
        return a.age > b.age;  // 年龄大者在前
    });
    for (const auto& e : arr) {
        e.print();
        cout << endl;
    }

    cout << "=====" << endl;

    // 3. 先按公司编号升序，再按年龄升序
    sort(arr.begin(), arr.end(), [](const Employee& a, const Employee& b) {
        if (a.company != b.company)
            return a.company < b.company;
        return a.age < b.age;
    });
    for (const auto& e : arr) {
        e.print();
        cout << endl;
    }

    // 4. TreeSet 按年龄升序（去重，因为比较器只比较年龄）
    set<Employee, EmployeeComparatorByAge> treeSet1;
    for (const auto& e : arr) {
        treeSet1.insert(e);
    }
    cout << treeSet1.size() << endl;  // 输出元素个数（去重后的）

    // 添加一个相同年龄但不同公司的员工（比较器只看年龄，所以会视为重复）
    treeSet1.insert(Employee(2, 27));
    cout << treeSet1.size() << endl;  // 大小不变（去重）

    cout << "===" << endl;

    // 5. 避免去重：使用 multiset 允许重复元素
    // 或者使用 set + 唯一 id 比较器
    // 此处演示使用 multiset（不去重）
    multiset<Employee, EmployeeComparatorByAge> treeSet2;
    for (const auto& e : arr) {
        treeSet2.insert(e);
    }
    cout << treeSet2.size() << endl;  // 6

    // 添加相同 company & age 的对象，multiset 允许插入
    treeSet2.insert(Employee(2, 27));
    cout << treeSet2.size() << endl;  // 7

    // 若想用 set 并保留不同对象，可使用唯一 id 比较器
    // 定义比较器：先比 company，再比 age，最后比 id
    auto comparatorWithId = [](const Employee& a, const Employee& b) {
        if (a.company != b.company) return a.company < b.company;
        if (a.age != b.age) return a.age < b.age;
        return a.id < b.id;  // 保证不同对象被视为不同
    };
    set<Employee, decltype(comparatorWithId)> treeSet3(comparatorWithId);
    // 填充数据...
    // 但此处不再重复，因为 multiset 已经达到效果

    cout << "===" << endl;

    // 6. 字符串字典序比较
    string str1 = "abcde";
    string str2 = "ks";
    cout << str1.compare(str2) << endl;  // 负数
    cout << str2.compare(str1) << endl;  // 正数

    return 0;
}