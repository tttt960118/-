#include <iostream>
#include <windows.h> // For SetConsoleOutputCP
using namespace std;

class Point2D
{
private:
    int x, y;
    static int count; // 静态成员变量，用于计数

public:
    // 构造函数，带默认参数，使用初始化列表
    Point2D(int x = 0, int y = 0) : x(x), y(y)
    {
        count++;
        cout << "创建 Point2D(" << x << ", " << y << "), 当前对象数: " << count << endl;
    }

    // 析构函数
    ~Point2D()
    {
        count--;
        cout << "销毁 Point2D(" << x << ", " << y << "), 剩余对象数: " << count << endl;
    }

    // 获取坐标
    int getX() const { return x; }
    int getY() const { return y; }

    // 设置坐标
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // 显示点信息
    void display() const
    {
        cout << "Point2D(" << x << ", " << y << ")" << endl;
    }

    // 获取当前对象计数
    static int getCount() { return count; }
};

// 初始化静态成员变量
int Point2D::count = 0;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "程序开始，当前对象数: " << Point2D::getCount() << endl
         << endl;

    // 创建几个Point2D对象
    Point2D p1; // 使用默认参数
    Point2D p2(3, 4);
    Point2D p3(7, 2);

    cout << endl
         << "当前对象数: " << Point2D::getCount() << endl
         << endl;

    // 使用块作用域演示析构函数调用
    {
        cout << "进入内部作用域..." << endl;
        Point2D p4(1, 1);
        Point2D p5(9, 9);
        cout << "内部作用域对象数: " << Point2D::getCount() << endl;
        cout << "退出内部作用域..." << endl;
    }

    cout << endl
         << "内部作用域外的对象数: " << Point2D::getCount() << endl
         << endl;

    // 动态分配对象
    cout << "动态分配对象..." << endl;
    Point2D *p6 = new Point2D(5, 5);
    cout << "动态分配后对象数: " << Point2D::getCount() << endl;

    // 释放动态分配的对象
    delete p6;
    cout << "释放动态对象后对象数: " << Point2D::getCount() << endl
         << endl;

    cout << "程序结束，剩余对象数: " << Point2D::getCount() << endl;
    return 0;
}