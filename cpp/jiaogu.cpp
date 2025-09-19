#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a < 0)
    {
        cout << "please input correctly!" << endl;
        return 0;
    }
    while (a > 1)
    {
        if (a % 2 == 0)
        {
            a /= 2;
        }
        else
        {
            a = a * 3 + 1;
        }
        cout << a << endl;
    }
    cout <<  "End!" << endl;
    return 0;
}