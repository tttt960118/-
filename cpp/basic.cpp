#include <iostream>

#include "basic.h" // Include the header file for declarations
void skip_main();

int main()
{
    using namespace std;             // Now std symbols are accessible without prefix
    cout << "Hello, World!" << endl; // Print Hello, World! to the console
    int a;
    cin >> a;      // Read an integer input from the user
    int value = a; // Example integer value for switch
    switch (value) // value must be an integer
    {
    case 1:
        cout << "Value is one." << endl;
        break;
    case 2:
        cout << "Value is two." << endl;
        break;
    default:
        cout << "Value is something else." << endl;
        skip_main();
        break;

    } // value is the number of cases
    return 0; // Return 0 to indicate successful execution
}
void skip_main()
{
    int x = 0;
    int y;
aaaa:
    std::cin >> y;//name space std(cin)

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

