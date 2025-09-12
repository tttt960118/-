#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>

struct Server
{
    long long weight, capactiy;
    Server(long long w, long long c) : weight(w), capactiy(c) {}
    Server() {}
};

// 题目核心：将服务器排序，使最大风险值最小
// 贪心方案：按 weight + capactiy 升序排列
// 每台服务器的风险值 = 上方所有weight之和 - 自身capactiy
// 返回所有服务器最大风险值的最小可能值

long long solve(Server *servers, long long n)
{
    std::vector<Server> arr(servers, servers + n);

    // 按 weight + capactiy 升序排序
    std::sort(arr.begin(), arr.end(), [](const Server &a, const Server &b)
              { return (a.weight + a.capactiy) < (b.weight + b.capactiy); });

    // 前缀和优化：prefix_weight[i] = 所有第i层及以上weight之和
    std::vector<long long> prefix_weight(n + 1, 0);
    for (long long i = n - 1; i >= 0; --i)
    {
        prefix_weight[i] = prefix_weight[i + 1] + arr[i].weight;
    }

    long long max_risk = LLONG_MIN;
    for (long long i = 0; i < n; ++i)
    {
        long long risk = prefix_weight[i + 1] - arr[i].capactiy;
        if (risk > max_risk)
            max_risk = risk;
    }

    return max_risk;
}
int main()
{
    Server servers[] = {
        Server(10, 5),
        Server(8, 7),
        Server(6, 9)};
    long long n = 3;
    long long result = solve(servers, n);
    printf("Min max risk:%lld\n", result);
    return 0;
}