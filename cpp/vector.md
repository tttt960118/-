# C++ Vector 使用指南

## 基本操作

### 初始化

```cpp
// 创建空vector
std::vector<int> vec1;

// 指定初始大小和默认值
std::vector<int> vec2(5);                // 5个元素，默认值为0
std::vector<int> vec3(5, 10);            // 5个元素，每个初始化为10

// 使用初始化列表
std::vector<int> vec4 = {1, 2, 3, 4, 5};
std::vector<int> vec5{1, 2, 3, 4, 5};    // 同上

// 从另一个vector初始化
std::vector<int> vec6(vec4);
std::vector<int> vec7 = vec4;
```

### 添加元素

```cpp
// 在末尾添加
vec1.push_back(1);
vec1.emplace_back(2);    // 更高效

// 在指定位置插入
vec1.insert(vec1.begin(), 0);    // 在开头插入0
```

### 访问元素

```cpp
// 下标访问（不检查越界）
int a = vec4[0];

// at函数（检查越界）
int b = vec4.at(1);

// 首尾元素
int first = vec4.front();
int last = vec4.back();

// 使用迭代器
auto it = vec4.begin();
int c = *it;
```

### 遍历方式

```cpp
// 下标遍历
for (size_t i = 0; i < vec4.size(); ++i) {
    std::cout << vec4[i] << " ";
}

// 范围for循环
for (int num : vec4) {
    std::cout << num << " ";
}

// 迭代器遍历
for (auto it = vec4.begin(); it != vec4.end(); ++it) {
    std::cout << *it << " ";
}
```

### 删除元素

```cpp
// 删除末尾元素
vec4.pop_back();

// 删除指定位置
vec4.erase(vec4.begin());        // 删除第一个
vec4.erase(vec4.begin() + 2);    // 删除第三个

// 删除范围
vec4.erase(vec4.begin(), vec4.begin() + 2);

// 清空所有元素
vec4.clear();
```

### 容量操作

```cpp
// 获取大小
size_t size = vec4.size();
bool isEmpty = vec4.empty();

// 调整大小
vec4.resize(10);         // 新元素默认为0
vec4.resize(15, 5);      // 新元素初始化为5

// 容量控制
size_t cap = vec4.capacity();
vec4.reserve(100);       // 预留空间

// 交换内容
vec4.swap(vec5);

```

## 代码示例

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // 用于排序等算法

int main() {
    // 1. 创建和初始化vector
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<std::string> names;
    
    // 2. 添加元素
    names.push_back("Alice");
    names.push_back("Bob");
    names.emplace_back("Charlie"); // 更高效的添加方式
    
    // 3. 访问元素
    std::cout << "第一个元素: " << numbers[0] << std::endl;
    std::cout << "第二个元素: " << numbers.at(1) << std::endl; // 带边界检查
    std::cout << "最后一个元素: " << numbers.back() << std::endl;
    
    // 4. 遍历vector
    std::cout << "\nnumbers中的元素: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    
    std::cout << "\n\nnames中的元素: ";
    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << *it << " ";
    }
    
    // 5. 修改元素
    numbers[2] = 42;
    std::cout << "\n\n修改后的第三个元素: " << numbers[2] << std::endl;
    
    // 6. 删除元素
    numbers.pop_back(); // 删除最后一个元素
    numbers.erase(numbers.begin() + 1); // 删除第二个元素
    
    // 7. 获取vector信息
    std::cout << "\nvector大小: " << numbers.size() << std::endl;
    std::cout << "vector容量: " << numbers.capacity() << std::endl;
    std::cout << "vector是否为空: " << (numbers.empty() ? "是" : "否") << std::endl;
    
    // 8. 清空vector
    names.clear();
    std::cout << "清空后names的大小: " << names.size() << std::endl;
    
    // 9. 排序vector
    std::sort(numbers.begin(), numbers.end());
    std::cout << "\n排序后的numbers: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    
    // 10. 二维vector示例
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    std::cout << "\n\n二维vector:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
```
