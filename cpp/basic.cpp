
#include <iostream>
#include <cctype> // For isspace
#include <vector>
#include <algorithm> // For sort
#include "basic.h"   // Include the header file for declarations

void skip_main()
{
    int x = 0;
    int y;
aaaa:
    std::cin >> y; // name space std(cin)

    if (y < 0)
    {
        goto aaaa; // Jump back to label aaaa if y is negative
    }
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0)
        {
            continue; // Skip even numbers
        }
        x += i; // Sum odd numbers
        printf("Current sum: %d\n", x);
    }
}

extern int ex_var; // Declaration of an external variable
int word_cnt(const char *s)
{
    int cnt = 0;
    while (*s != '\0')
    {
        while (isspace(*s))
            ++s; // 跳过空白字符
        if (*s != '\0')
        {
            ++cnt; // 找到一个单词
            while (!isspace(*s) && *s != '\0')
                ++s; // 跳过单词
        }
    }
    return cnt;
}

class medianFinder
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int n1 = nums1.size(); // Get the size of nums1
        int n2 = nums2.size();
        std::vector<int> nums;
        nums.reserve(n1 + n2);
        nums.insert(nums.end(), nums1.begin(), nums1.end()); // Append elements of nums1
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        std::sort(nums.begin(), nums.end()); // Sort the combined vector
        int full_length = nums.size();
        if (full_length % 2 == 0)
        {
            // 为了避免整数溢出，我们将两个数转换为double再相加
            return (static_cast<double>(nums[full_length / 2 - 1]) + static_cast<double>(nums[full_length / 2])) / 2.0; // Return the average of the two middle elements  //static_cast<double>用于执行安全的类型转换
        }
        else
        {
            return static_cast<double>(nums[full_length / 2]);
        }
    }
};