#include <iostream>
#include <stack>
using namespace std;

void move(int n, int start[], int finish[], int temp[])
{
    if (n == 1)
    {
        finish[0] = start[0];
        return;
    }
    finish[n - 1] = start[n - 1];
    move(n - 1, start, temp, finish);
}

int main()
{
    int n = 6;
    int start[6];
    int fi[6];
    int tep[6];
    for (int i = 0; i < n; i++)
    {
        start[i] = i + 1;
        fi[i] = 0;
        tep[i] = 6;
    }
    move(n, start, fi, tep);
    for (int i = 0; i < n; i++)
    {
        cout << fi[i] << endl;
    }
}
