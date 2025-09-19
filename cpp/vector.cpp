#include <iostream>
#include <vector>
#include <algorithm> // 用于排序等算法

int main()
{
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
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    std::cout << "\n\nnames中的元素: ";
    for (auto it = names.begin(); it != names.end(); ++it)
    {
        std::cout << *it << " ";
    }

    // 5. 修改元素
    numbers[2] = 42;
    std::cout << "\n\n修改后的第三个元素: " << numbers[2] << std::endl;

    // 6. 删除元素
    numbers.pop_back();                 // 删除最后一个元素
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
    for (int num : numbers)
    {
        std::cout << num << " ";
    }

    // 10. 二维vector示例
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    std::cout << "\n\n二维vector:" << std::endl;
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}