#include <iostream>
using namespace std;


class Tensor
{
public:
    int x, y;
    Tensor(int x, int y) : x(x), y(y) {};
    Tensor operator+(const Tensor &other)
    { // 重载加法运算符
        return Tensor(x + other.x, y + other.y);
    }
};
int main()
{Tensor t1(1, 2);
Tensor t2(3, 4);

Tensor t3 = t1 + t2; // 使用重载的加法运算符
cout << t3.x << ", " << t3.y << endl; // 输出结果
}