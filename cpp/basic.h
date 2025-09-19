#ifndef BASIC_H
#define BASIC_H
#include <iostream>
#include <cctype> // For isspace
#include <vector>
#include <algorithm> // For sort
void skip_main();

template <class T, class U, class V>
V add1(T a, U b) // Template function to add two values
{
    return a + b; // Return the sum of a and b
}
extern int ex_var; // Declaration of an external variable
int word_cnt(const char *s);

template <typename T>
T add(T a, T b)
{
    return a + b;
}
class medianFinder;

#endif