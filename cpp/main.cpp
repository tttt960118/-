#include <iostream>
#include <cctype> // For isspace
#include <vector>
#include "basic.h" // Include the header file for declarations
int ex_var = 42;   // Definition of the external variable
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
        int b = add1<int, double, double>(3, 4.5);              // Call the template function with int and double
        int c = add1<char, char, int>('A', 'B');                // Call the template function with char
        int d = add1<char, char, char>('A', 'B');               // Call the template function with int
        cout << "Sum of 3 and 4.5 is: " << b << endl;           // Output the result
        cout << "Sum of 'A' and 'B' is: " << c << endl;         // Output the result
        cout << "Sum of 'A' and 'B' as char is: " << d << endl; // Output the result
        cout << "External variable ex_var: " << ex_var << endl; // Output the
        word_cnt("Hello, this is a test string.");              // Call word_cnt function
        cout << "Word count: " << word_cnt("Hello, this is a test string.") << endl;
        break;

    } // value is the number of cases
    return 0; // Return 0 to indicate successful execution
}
